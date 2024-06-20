#include "hde/hde32.h"
#include "sdk.h"
#include "util.h"

#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <unordered_map>

static bool aborted;

/*
 * dump signatures based on logging functions
 */
void dump_sigs( ) {
	printf( "[+] dumping signatures...\n" );

	/* open file for writing */
	std::ofstream file;
	file.open( "signatures.md" );
	file << "# Signatures\n"
						<< std::endl;

	/* ==== loop through all modules ==== */
	size_t count = 0;

	for ( const auto module : util::mem::dump_modules( ) ) {
		/* find import address of log functions */
		std::vector<std::uint8_t *> addrs;

		const char *syms[ 2 ] = {
			"?EnterScope@CVProfile@@QAEXPBDH0_NH@Z",
			"COM_TimestampedLog" };
		for ( const auto sym : syms ) {
			const auto fn = util::mem::get_import_addr( module.base, "tier0.dll", sym );

			/* create asm instruction */
			uint8_t ins[ 6 ] = { 0xFF, 0x15 };  // jmp
			memcpy( ins + 2, &fn, 4 );          // address in little endian

			const auto _addrs = util::mem::multi_scan( module.base, ins, 6 );
			addrs.insert( addrs.end( ), _addrs.begin( ), _addrs.end( ) );
		}

		if ( addrs.empty( ) )
			continue;

		printf( "[+] %s: 0/%d\r", module.name, addrs.size( ) );

		file << util::str::ssprintf( "## %s", module.name ) << std::endl;
		file << "|Function|Signature|" << std::endl;
		file << "|---|---|" << std::endl;

		std::string prev_pattern;
		size_t distinct = 0;  // number of distinct functions
		for ( const auto addr : addrs ) {
			if ( aborted ) {
				printf( "\n[-] aborting...\n" );

				file << "> [!WARNING]" << std::endl;
				file << "> This dump was aborted while running and is incomplete." << std::endl;

				return;
			}

			std::string name, pattern;

			/* read passed arg */
			uint8_t *p = addr - sizeof( void * );
			while ( p[ 0 ] != 0x68 && addr - p < 32 ) {
				--p;
				if ( p[ 0 ] == 0x68 )
					name = std::string( *reinterpret_cast<const char **>( p + 0x1 ) );
			}

			/* remove newlines */
			name.erase( std::remove( name.begin( ), name.end( ), '\n' ), name.end( ) );

			/* find start of fn to make signature */
			/*
			 * TODO: find better way to trace back the start of a function
			 * with this current one we miss a lot and get some wrong signatures
			 */
			while ( *( uint32_t * ) p != 0xEC8B55CC ) {
				--p;
				if ( *( uint32_t * ) p == 0xEC8B55CC ) {
					/* create signature */
					++p;
					for ( size_t j = 0; j < 64; ) {
						/* disassemble instruction to see if we need to add wildcards */
						hde32s ins;
						hde32_disasm( p + j, &ins );

						auto data_size = ins.len - ( ins.flags & F_MODRM ? 2 : 1 );

						for ( size_t k = 0; k < ins.len; ++k ) {
							if ( k < ins.len - data_size )
								pattern += util::str::ssprintf( "%02x ", p[ j + k ] );
							else
								pattern += "?? ";
						}

						j += ins.len;
					}

					break;
				}
			}

			/* check if unique and strip down sig until it stays unique */
			auto test = util::mem::multi_scan( module.base, pattern.c_str( ) );
			while ( test.size( ) == 1 ) {
				auto tmp = pattern;
				tmp = tmp.substr( 0, tmp.size( ) - 3 );

				test = util::mem::multi_scan( module.base, tmp.c_str( ) );
				if ( test.size( ) > 1 )
					break;

				pattern = tmp;
			}

			/* remove trailing wildcards */
			while ( pattern[ pattern.size( ) - 2 ] == '?' ) {
				pattern = pattern.substr( 0, pattern.size( ) - 3 );
			}

			/* remove trailing space */
			pattern.pop_back( );

			/* finally append to file */
			if ( !name.empty( ) && !pattern.empty( ) && pattern != prev_pattern ) {
				file << util::str::ssprintf( "|%s|`%s`|", name.c_str( ), pattern.c_str( ) ) << std::endl;

				++distinct;

				printf( "[+] %s: %d/%d\r", module.name, distinct, addrs.size( ) );

				prev_pattern = pattern;
			}
		}

		count += distinct;

		printf( "[+] %s: %d/%d (DONE)\n", module.name, distinct, addrs.size( ) );
	}

	file.close( );

	printf( "[+] dumped %d signatures to \"signatures.md\".\n", count );
}

/*
 * dump netvars from list
 */
void dump_netvars( ) {
	printf( "[+] dumping netvars...\n" );

	/* open file for writing */
	std::ofstream file;
	file.open( "netvars.md" );
	file << "# Netvars\n"
						<< std::endl;

	const auto client = sdk::get_interface<sdk::i_client>( "client.dll", "VClient016" );

	/* ==== recursively dump all netvars ==== */
	size_t count = 0;

	struct recv_class {
		std::string name;
		std::vector<sdk::recv_prop> props;
	};
	std::vector<recv_class> classes;

	std::function<void( const char *, sdk::recv_table *, uint32_t )> recursive_dump;
	recursive_dump = [ & ]( const char *baseclass, sdk::recv_table *table, uint32_t offset ) {
		auto cur_class = recv_class( );
		for ( size_t i = 0; i < table->props_count; ++i ) {
			const auto prop = &table->props[ i ];

			/* sanity checks */
			if ( table->props_count < 3 )
				continue;

			if ( !prop || isdigit( prop->prop_name[ 0 ] ) )
				continue;

			if ( i == 0 ) {
				cur_class.name = baseclass;
				continue;
			}

			if ( prop->prop_type == sdk::send_prop_type::_data_table && prop->data_table && prop->data_table->table_name[ 0 ] == 'D' )
				recursive_dump( baseclass, prop->data_table, offset + prop->offset );

			sdk::recv_prop custom_prop = *prop;
			custom_prop.offset = offset + prop->offset;
			custom_prop.prop_type = ( sdk::send_prop_type )( custom_prop.prop_type + 1 );
			cur_class.props.push_back( custom_prop );

			++count;
		}

		if ( !cur_class.name.empty( ) )
			classes.push_back( cur_class );
	};

	/* go through each class and dump */
	for ( auto client_class = client->get_all_classes( ); client_class; client_class = client_class->next_ptr ) {
		if ( client_class->recvtable_ptr )
			recursive_dump( client_class->network_name, client_class->recvtable_ptr, 0 );
	}

	for ( auto &client_class : classes ) {
		file << util::str::ssprintf( "## %s", client_class.name.c_str( ) ) << std::endl;
		file << util::str::ssprintf( "```cpp\nstruct %s {", client_class.name.c_str( ) ) << std::endl;

		/* sort by offset */

		std::sort( client_class.props.begin( ), client_class.props.end( ), []( const sdk::recv_prop &lhs, const sdk::recv_prop &rhs ) {
			return lhs.offset < rhs.offset;
		} );

		for ( size_t i = 0; i < client_class.props.size( ); ++i ) {
			const auto prop = &client_class.props[ i ];

			auto last_prop = sdk::recv_prop( );
			if ( i > 0 )
				last_prop = client_class.props[ i - 1 ];

			/* type information */
			std::vector<std::pair<const char *, size_t>> types {
				{ "unknown", 0 },
				{ "int32_t ", 4 },
				{ "float ", 4 },
				{ "vec3_t ", 12 },
				{ "vec2_t ", 8 },
				{ "char *", 4 },
				{ "char *", 4 },  // not sure bout this one
				{ "void *", 4 },  // not sure bout this one
				{ "int64_t ", 8 } };

			/* add alignment offset */
			int offset = prop->offset - last_prop.offset - types[ last_prop.prop_type ].second;
			if ( offset > 0 ) {
				file << util::str::ssprintf( "	char pad_%04x[%d];  // 0x%04x", prop->offset, offset, last_prop.offset + types[ last_prop.prop_type ].second ) << std::endl;
			}

			file << util::str::ssprintf( "	%s%s;  // 0x%04x", types[ prop->prop_type ].first, prop->prop_name, prop->offset ) << std::endl;
		}

		file << "}\n```" << std::endl;
	}

	file.close( );

	printf( "[+] dumped %d netvars to \"netvars.md\".\n", count );
}

/*
 * dump all interfaces
 */
void dump_ifaces( ) {
	printf( "[+] dumping interfaces...\n" );

	/* open file for writing */
	std::ofstream file;
	file.open( "interfaces.md" );
	file << "# Interfaces\n"
						<< std::endl;

	class interface_reg {
	public:
		BYTE createfn[ 4 ];
		const char *name;
		interface_reg *next;
	};

	/* ==== loop through all interfaces from all modules ==== */
	size_t count = 0;
	for ( const auto module : util::mem::dump_modules( ) ) {
		/*
		 * TODO: find real fix lol
		 */
		if ( !strcmp( module.name, "steamclient.dll" ) || !strcmp( module.name, "crashhandler.dll" ) )
			continue;

		void *fn = GetProcAddress( ( HMODULE ) module.base, "CreateInterface" );
		if ( fn ) {
			auto var01 = ( ( uintptr_t ) fn + 0x8 );
			if ( !var01 ) continue;

			auto var02 = *( unsigned short * ) ( ( uintptr_t ) fn + 0x5 );
			if ( !var02 ) continue;

			auto var03 = *( unsigned short * ) ( ( uintptr_t ) fn + 0x7 );
			if ( !var03 ) continue;

			auto var04 = ( uintptr_t ) ( var01 + ( var02 - var03 ) );
			if ( !var04 ) continue;

			interface_reg *reg = **( interface_reg *** ) ( var04 + 0x6 );
			if ( !reg ) continue;

			file << util::str::ssprintf( "## %s", module.name ) << std::endl;
			file << "|Module|Interface|" << std::endl;
			file << "|---|---|" << std::endl;

			for ( interface_reg *cur = reg; cur; cur = cur->next ) {
				file << util::str::ssprintf( "|%s|%s|", module.name, cur->name ) << std::endl;

				++count;
			}
		}
	}

	file.close( );

	printf( "[+] dumped %d interfaces to \"interfaces.md\".\n", count );
}

void main( HMODULE instance ) {
	/* attach console */
	AllocConsole( );
	freopen_s( reinterpret_cast<_iobuf **>( __acrt_iob_func( 0 ) ), "conin$", "r", static_cast<_iobuf *>( __acrt_iob_func( 0 ) ) );
	freopen_s( reinterpret_cast<_iobuf **>( __acrt_iob_func( 1 ) ), "conout$", "w", static_cast<_iobuf *>( __acrt_iob_func( 1 ) ) );
	freopen_s( reinterpret_cast<_iobuf **>( __acrt_iob_func( 2 ) ), "conout$", "w", static_cast<_iobuf *>( __acrt_iob_func( 2 ) ) );

	/* fancy print */
	printf( R"(
          ___       __              
    ____ |__ \ ____/ /___ ___  ____ 
   / __ \__/ // __  / __ `__ \/ __ \
  / /_/ / __// /_/ / / / / / / /_/ /
 / .___/____/\__,_/_/ /_/ /_/ .___/ 
/_/                        /_/      
)" );
	printf( "\nwhat would you like to dump?\n" );
	printf( "1. signatures\n" );
	printf( "2. netvars\n" );
	printf( "3. interfaces\n" );
	printf( "> " );

	int choice;
	std::cin >> choice;

	switch ( choice ) {
	case 1:
		dump_sigs( );
		break;
	case 2:
		dump_netvars( );
		break;
	case 3:
		dump_ifaces( );
		break;
	}

	/* ==== exit ==== */
	printf( "[-] exiting in 3 seconds...\n" );

	aborted = true;

	Sleep( 3000 );

	/* deattach console */
	fclose( static_cast<_iobuf *>( __acrt_iob_func( 0 ) ) );
	fclose( static_cast<_iobuf *>( __acrt_iob_func( 1 ) ) );
	fclose( static_cast<_iobuf *>( __acrt_iob_func( 2 ) ) );
	FreeConsole( );

	/* exit thread */
	FreeLibraryAndExitThread( instance, 0 );
}

void exit_thread( ) {
	while ( !aborted ) {
		if ( GetAsyncKeyState( VK_ESCAPE ) ) {
			aborted = true;
			break;
		}

		Sleep( 100 );
	}
}

int __stdcall DllMain( HMODULE module, DWORD reason_for_call, LPVOID reserved ) {
	if ( reason_for_call == DLL_PROCESS_ATTACH ) {
		DisableThreadLibraryCalls( module );

		const auto thread = CreateThread( nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>( main ), module, 0, nullptr );
		CreateThread( nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>( exit_thread ), nullptr, 0, nullptr );

		if ( thread )
			CloseHandle( thread );
	}

	return 1;
}
