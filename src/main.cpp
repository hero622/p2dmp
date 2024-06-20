#include "hde/hde32.h"
#include "util.h"

#include <fstream>
#include <iostream>

static bool aborted;

/*
 * dump signatures based on logging functions
 */
void dump_sigs( ) {
	/* open file for writing */
	std::ofstream file;
	file.open( "signatures.md" );
	file << "# Signatures\n"
						<< std::endl;
	file << "|Module|Function|Signature|" << std::endl;
	file << "|---|---|---|" << std::endl;

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

			/* find start of fn to make signature */
			/*
			 * TODO: find better way to trace back the start of a function
			 * with this current one we miss a lot and get some wrong signatures
			 */
			while ( !( p[ 0 ] == 0xCC && p[ 1 ] == 0x55 ) ) {
				--p;
				if ( p[ 0 ] == 0xCC && p[ 1 ] == 0x55 ) {
					/* create signature */
					p += 2;
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
				file << util::str::ssprintf( "|%s|%s|%s|", module.name, name.c_str( ), pattern.c_str( ) ) << std::endl;

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
		break;
	case 3:
		break;
	}

	/* ==== exit ==== */
	printf( "[-] exiting in 3 seconds...\n" );

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
	while ( true ) {
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
