#include "hde/hde32.h"
#include "sdk.h"
#include "util.h"

#include <algorithm>
#include <chrono>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <set>

#pragma warning( disable : 4996 );

#define LOG_TIMESTAMP( )                                                                                                                   \
	{                                                                                                                                         \
		time_t now = time( 0 );                                                                                                                  \
		tm *gmtm = gmtime( &now );                                                                                                               \
		char buf[ 80 ];                                                                                                                          \
		strftime( buf, sizeof( buf ), "%d/%m/%Y at %X", gmtm );                                                                                  \
		file << util::str::ssprintf( "This dump was generated using [p2dmp](https://github.com/hero622/p2dmp) on %s (UTC).", buf ) << std::endl; \
	}

static bool aborted;

/*
 * dump signatures based on logging functions
 */
void dump_sigs( ) {
	printf( "[+] dumping signatures...\n" );

	/* open file for writing */
	std::ofstream file;
	file.open( "signatures.md" );
	file << "# Signatures" << std::endl;
	LOG_TIMESTAMP( );

	/* ==== loop through all modules ==== */
	size_t count = 0;

	for ( const auto module : util::mem::dump_modules( ) ) {
		/* find import address of log functions */
		std::vector< std::uint8_t * > addrs;

		const char *syms[ 13 ] = {
			"?EnterScope@CVProfile@@QAEXPBDH0_NH@Z",
			"?DevWarning@@YAXPBDZZ",
			"CommandLine",
			"Msg",
			"Error",
			"DevWarning",
			"Warning",
			"?DevMsg@@YAXPBDZZ",
			"?ConColorMsg@@YAXABVColor@@PBDZZ",
			"ConDMsg",
			"COM_TimestampedLog",
			"?LoggingSystem_Log@@YA?AW4LoggingResponse_t@@HW4LoggingSeverity_t@@VColor@@PBDZZ",
			"DevMsg" };
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

		std::set< std::string > patterns;
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
				if ( p[ 0 ] == 0x68 ) {
					/* fuk it */
					try {
						name = std::string( *reinterpret_cast< const char ** >( p + 0x1 ) );
					} catch ( ... ) {
						continue;
					}
				}
			}

			/* remove newlines */
			name.erase( std::remove( name.begin( ), name.end( ), '\n' ), name.end( ) );

			/* ==== check if looks like a function ==== */
			/* check special characters */
			size_t char_pos = name.find( "::" );
			if ( char_pos == std::string::npos ) char_pos = name.find( "()" );
			if ( char_pos == std::string::npos ) char_pos = name.find( "_" );
			if ( char_pos == std::string::npos ) continue;

			/* strip down to fn name */
			size_t start_pos = name.substr( 0, char_pos ).find_last_of( " !#$%&\"()*+,-." );
			if ( start_pos == std::string::npos ) start_pos = 0;
			size_t end_pos1 = name.substr( char_pos ).find_first_of( " !#$%&\"()*+,-." );
			size_t end_pos2 = name.substr( char_pos + 2 ).find( ":" );
			if ( end_pos2 != std::string::npos ) end_pos2 += 2;
			size_t end_pos = min( end_pos1, end_pos2 );  // whichever one comes first
			if ( end_pos == std::string::npos ) end_pos = name.length( );
			name = name.substr( start_pos, end_pos - start_pos + char_pos );

			/* check all lower or all uppercase (Valve uses CamelCase so this shouldnt happen) */
			bool lowercase = true;
			bool uppercase = true;
			for ( char &c : name ) {
				if ( isupper( c ) )
					lowercase = false;
				else if ( islower( c ) )
					uppercase = false;
			}
			if ( lowercase || uppercase )
				continue;

			/* find start of fn to make signature */
			/*
			 * TODO: find better way to trace back the start of a function
			 * with this current one we miss a lot and get some wrong signatures
			 */
			while ( !( *( uint32_t * ) p == 0xEC8B55CC || *( uint32_t * ) p == 0xEC8B55C3 ) ) {
				--p;
				if ( *( uint32_t * ) p == 0xEC8B55CC || *( uint32_t * ) p == 0xEC8B55C3 ) {
					/* create signature */
					++p;
					for ( size_t j = 0; j < 50; ) {
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
			if ( !name.empty( ) && !pattern.empty( ) && patterns.find( pattern ) == patterns.end( ) ) {
				if ( patterns.empty( ) ) {
					printf( "[+] %s: 0/%d\r", module.name, addrs.size( ) );

					file << util::str::ssprintf( "## %s", module.name ) << std::endl;
					file << "|Function|Signature|" << std::endl;
					file << "|---|---|" << std::endl;
				}

				patterns.insert( pattern );

				file << util::str::ssprintf( "|%s|`%s`|", name.c_str( ), pattern.c_str( ) ) << std::endl;

				printf( "[+] %s: %d/%d\r", module.name, patterns.size( ), addrs.size( ) );
			}
		}

		count += patterns.size( );

		printf( "[+] %s: %d/%d (DONE)\n", module.name, patterns.size( ), addrs.size( ) );
	}

	file.close( );

	printf( "[+] dumped %d signatures to \"signatures.md\".\n", count );
}

/*
 * dump classes built from netvars and datamaps
 */
void dump_classes( ) {
	printf( "[+] dumping classes...\n" );

	/* open file for writing */
	std::ofstream file;
	file.open( "classes.md" );
	file << "# Classes" << std::endl;
	LOG_TIMESTAMP( );

	const auto client = sdk::get_interface< sdk::i_client >( "client.dll", "VClient016" );

	/* ==== recursively dump all netvars ==== */
	size_t count = 0;

	struct sdk_prop {
		std::string name;
		int type;
		int offset;
		bool is_netvar;
	};

	struct sdk_class {
		std::string name;
		std::vector< sdk_prop > props;
	};
	std::vector< sdk_class > classes;

	auto cur_class = new sdk_class( );

	std::function< void( const char *, sdk::recv_table *, uint32_t ) > recursive_dump;
	recursive_dump = [ & ]( const char *baseclass, sdk::recv_table *table, uint32_t offset ) {
		for ( size_t i = 0; i < table->props_count; ++i ) {
			const auto prop = &table->props[ i ];

			/* sanity checks */
			if ( table->props_count < 3 )
				continue;

			if ( !prop || isdigit( prop->prop_name[ 0 ] ) )
				continue;

			if ( i == 0 && baseclass != cur_class->name ) {
				auto tmp = sdk_class( );
				tmp.name = baseclass;
				if ( !tmp.name.empty( ) ) {
					classes.push_back( tmp );
					cur_class = &classes.back( );
				}

				continue;
			}

			if ( prop->prop_type == sdk::send_prop_type::_data_table && prop->data_table && prop->data_table->table_name[ 0 ] == 'D' )
				recursive_dump( baseclass, prop->data_table, offset + prop->offset );

			sdk_prop custom_prop;
			custom_prop.name = prop->prop_name;
			custom_prop.type = prop->prop_type + 1;
			custom_prop.offset = offset + prop->offset;
			custom_prop.is_netvar = true;
			cur_class->props.push_back( custom_prop );

			++count;
		}
	};

	/* go through each class and dump */
	for ( auto client_class = client->get_all_classes( ); client_class; client_class = client_class->next_ptr ) {
		if ( client_class->recvtable_ptr )
			recursive_dump( client_class->network_name, client_class->recvtable_ptr, 0 );
	}

	/* ==== dump datamaps ==== */
	const auto addrs = util::mem::multi_scan( GetModuleHandleA( "client.dll" ), "C7 05 ? ? ? ? ? ? ? ? C7 05 ? ? ? ? ? ? ? ? C3 CC" );
	for ( const auto addr : addrs ) {
		sdk::datamap_t *map = reinterpret_cast< sdk::datamap_t * >( *( uintptr_t * ) ( addr + 0x2 ) - sizeof( void * ) );

		/* sanity checks */
		if ( !map || !map->data_num_fields || map->data_num_fields > 200 || !map->data_desc || !map->data_class_name )
			continue;

		for ( int i = 0; i < map->data_num_fields; ++i ) {
			const auto prop = &map->data_desc[ i ];
			if ( !prop->field_name )
				continue;

			if ( i == 0 ) {
				/* check if class already exists, if not make new one */
				auto it = std::find_if( classes.begin( ), classes.end( ), [ & ]( const sdk_class &x ) {
					return x.name == map->data_class_name;
				} );
				if ( it != classes.end( ) )
					cur_class = &classes[ std::distance( classes.begin( ), it ) ];
				else {
					auto tmp = sdk_class( );
					tmp.name = map->data_class_name;
					if ( !tmp.name.empty( ) ) {
						classes.push_back( tmp );
						cur_class = &classes.back( );
					}
				}
			}

			sdk_prop custom_prop;
			custom_prop.name = prop->field_name;
			custom_prop.type = prop->field_type + 9;
			custom_prop.offset = prop->field_offset;
			custom_prop.is_netvar = false;
			cur_class->props.push_back( custom_prop );

			++count;
		}
	}

	/* ==== write dumps to file ==== */
	for ( auto &client_class : classes ) {
		file << util::str::ssprintf( "## %s", client_class.name.c_str( ) ) << std::endl;
		file << util::str::ssprintf( "```cpp\nstruct %s {", client_class.name.c_str( ) ) << std::endl;

		/* sort by offset */
		std::sort( client_class.props.begin( ), client_class.props.end( ), []( const sdk_prop &lhs, const sdk_prop &rhs ) {
			return lhs.offset < rhs.offset;
		} );

		for ( size_t i = 0; i < client_class.props.size( ); ++i ) {
			const auto prop = &client_class.props[ i ];

			auto last_prop = sdk_prop( );
			if ( i > 0 ) {
				last_prop = client_class.props[ i - 1 ];

				if ( prop->offset == last_prop.offset )
					continue;
			}

			/* type information */
			std::pair< const char *, size_t > types[ 40 ] {
				{ "void ", 0 },  // NOTE: this is shifted
				{ "int32_t ", 4 },
				{ "float ", 4 },
				{ "vec3_t ", 12 },
				{ "vec2_t ", 8 },
				{ "char *", 4 },
				{ "char *", 4 },  // not sure bout this one
				{ "void *", 4 },  // not sure bout this one
				{ "int64_t ", 8 },
				{ "void ", 0 },
				{ "float ", 4 },
				{ "char *", 4 },
				{ "vec3_t ", 12 },
				{ "vec4_t ", 16 },
				{ "int32_t ", 4 },
				{ "bool ", 1 },  // ORIGINAL NOTE: boolean, implemented as an int, I may use this as a hint for compression
				{ "int16_t ", 2 },
				{ "char ", 1 },
				{ "Color ", 32 },
				{ "void *", 4 },  // idk bout this one
				{ "void *", 4 },  // ditto
				{ "CBaseEntity *", 4 },
				{ "EHandle ", 4 },
				{ "edict_t *", 4 },
				{ "vec3_t ", 12 },
				{ "float ", 4 },
				{ "int32_t ", 4 },  // might be unsigned
				{ "char *", 4 },
				{ "char *", 4 },
				{ "void *", 4 },  // IDK
				{ "void *", 4 },
				{ "VMatrix ", 64 },
				{ "VMatrix ", 64 },
				{ "matrix3x4_t", 48 },
				{ "float ", 4 },
				{ "int32_t ", 4 },  // might be size_t
				{ "int32_t ", 4 },  // this too
				{ "vec2_t ", 8 },
				/* only here because some of them are incorrect */
				{ "void *", 4 },
				{ "void *", 4 },
			};

			/* add alignment offset */
			int offset = prop->offset - last_prop.offset - types[ last_prop.type ].second;
			if ( offset > 0 ) {
				file << util::str::ssprintf( "	char pad_%04x[%d];  // 0x%04x", prop->offset, offset, last_prop.offset + types[ last_prop.type ].second ) << std::endl;
			}

			file << util::str::ssprintf( "	%s%s;  // 0x%04x", types[ prop->type ].first, prop->name.c_str( ), prop->offset ) << std::endl;
		}

		file << "}\n```" << std::endl;
	}

	file.close( );

	printf( "[+] dumped %d fields to \"classes.md\".\n", count );
}

/*
 * dump all interfaces
 */
void dump_ifaces( ) {
	printf( "[+] dumping interfaces...\n" );

	/* open file for writing */
	std::ofstream file;
	file.open( "interfaces.md" );
	file << "# Interfaces" << std::endl;
	LOG_TIMESTAMP( );

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
		if ( !strcmp( module.name, "steamclient.dll" ) || !strcmp( module.name, "crashhandler.dll" ) || !strcmp( module.name, "vstdlib_s.dll" ) )
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

			/* filter out unique */
			std::set< const char * > ifaces;
			for ( interface_reg *cur = reg; cur; cur = cur->next ) {
				ifaces.insert( cur->name );
			}
			for ( const auto iface : ifaces ) {
				file << util::str::ssprintf( "|%s|%s|", module.name, iface ) << std::endl;

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
	freopen_s( reinterpret_cast< _iobuf ** >( __acrt_iob_func( 0 ) ), "conin$", "r", static_cast< _iobuf * >( __acrt_iob_func( 0 ) ) );
	freopen_s( reinterpret_cast< _iobuf ** >( __acrt_iob_func( 1 ) ), "conout$", "w", static_cast< _iobuf * >( __acrt_iob_func( 1 ) ) );
	freopen_s( reinterpret_cast< _iobuf ** >( __acrt_iob_func( 2 ) ), "conout$", "w", static_cast< _iobuf * >( __acrt_iob_func( 2 ) ) );

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
	printf( "2. classes\n" );
	printf( "3. interfaces\n" );
	printf( "> " );

	int choice;
	std::cin >> choice;

	switch ( choice ) {
	case 1:
		dump_sigs( );
		break;
	case 2:
		dump_classes( );
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
	fclose( static_cast< _iobuf * >( __acrt_iob_func( 0 ) ) );
	fclose( static_cast< _iobuf * >( __acrt_iob_func( 1 ) ) );
	fclose( static_cast< _iobuf * >( __acrt_iob_func( 2 ) ) );
	FreeConsole( );

	/* exit thread */
	FreeLibraryAndExitThread( instance, 0 );
}

void exit_thread( ) {
	while ( !aborted ) {
		/* dont listen to keypress while tabbed out */
		HWND hwnd = GetConsoleWindow( );
		if ( GetAsyncKeyState( VK_ESCAPE ) && GetForegroundWindow( ) == hwnd ) {
			aborted = true;
			break;
		}

		Sleep( 100 );
	}
}

int __stdcall DllMain( HMODULE module, DWORD reason_for_call, LPVOID reserved ) {
	if ( reason_for_call == DLL_PROCESS_ATTACH ) {
		DisableThreadLibraryCalls( module );

		const auto thread = CreateThread( nullptr, 0, reinterpret_cast< LPTHREAD_START_ROUTINE >( main ), module, 0, nullptr );
		CreateThread( nullptr, 0, reinterpret_cast< LPTHREAD_START_ROUTINE >( exit_thread ), nullptr, 0, nullptr );

		if ( thread )
			CloseHandle( thread );
	}

	return 1;
}
