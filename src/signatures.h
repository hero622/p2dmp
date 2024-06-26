#pragma once

#include "hde/hde32.h"
#include "sdk.h"
#include "util.h"

#include <fstream>
#include <set>

class signatures {
private:
	static inline bool g_aborted;

	/*
	 * search for functions that call logging functions
	 */
	static void search( void *module_handle, std::vector< std::uint8_t * > &addrs ) {
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
		for ( const auto &sym : syms ) {
			const auto fn = util::mem::get_import_addr( module_handle, "tier0.dll", sym );

			/* create asm instruction */
			uint8_t ins[ 6 ] = { 0xFF, 0x15 };  // jmp
			memcpy( ins + 2, &fn, 4 );          // address in little endian

			const auto _addrs = util::mem::multi_scan( module_handle, ins, 6 );
			addrs.insert( addrs.end( ), _addrs.begin( ), _addrs.end( ) );
		}
	}

	/*
	 * check if looks like a function, clean up name
	 */
	static bool cleanup_name( std::string &name ) {
		/* remove newlines */
		name.erase( std::remove( name.begin( ), name.end( ), '\n' ), name.end( ) );

		/* check special characters */
		size_t char_pos = name.find( "::" );
		if ( char_pos == std::string::npos ) char_pos = name.find( "()" );
		if ( char_pos == std::string::npos ) char_pos = name.find( "_" );
		if ( char_pos == std::string::npos ) return false;

		/* strip down to fn name */
		size_t start_pos = name.substr( 0, char_pos ).find_last_of( " !#$%&\"()*+,-." );
		if ( start_pos != std::string::npos ) start_pos += 1;
		size_t end_pos1 = name.substr( char_pos ).find_first_of( " !#$%&\"()*+,-." );
		size_t end_pos2 = name.substr( char_pos + 2 ).find( ":" );
		if ( end_pos2 != std::string::npos ) end_pos2 += 2;
		size_t end_pos = min( end_pos1, end_pos2 );  // whichever one comes first
		if ( start_pos == std::string::npos ) start_pos = 0;
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
			return false;

		return true;
	}

	/*
	 * make signature
	 */
	static void make_signature( void *module_handle, uint8_t *p, std::string &pattern ) {
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
		auto test = util::mem::multi_scan( module_handle, pattern.c_str( ) );
		while ( test.size( ) == 1 ) {
			auto tmp = pattern;
			tmp = tmp.substr( 0, tmp.size( ) - 3 );

			test = util::mem::multi_scan( module_handle, tmp.c_str( ) );
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
	}

public:
	/*
	 * dump signatures based on logging functions
	 */
	static void dump( ) {
		printf( "[+] dumping signatures...\n" );

		/* open file for writing */
		std::ofstream file;
		file.open( "signatures.md" );
		file << "# Signatures" << std::endl;
		LOG_TIMESTAMP( );

		/* ==== loop through all modules ==== */
		size_t count = 0;
		for ( const auto &module : util::mem::dump_modules( ) ) {
			/* find import address of log functions */
			std::vector< std::uint8_t * > addrs;
			search( module.base, addrs );

			if ( addrs.empty( ) ) continue;

			std::set< std::string > patterns;
			for ( const auto &addr : addrs ) {
				if ( g_aborted ) {
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

				if ( !cleanup_name( name ) )
					continue;

				make_signature( module.base, p, pattern );

				/* finally append to file */
				if ( !name.empty( ) && !pattern.empty( ) ) {
					if ( patterns.empty( ) ) {
						printf( "[+] %s: 0/%d\r", module.name, addrs.size( ) );

						file << util::str::ssprintf( "## %s", module.name ) << std::endl;
						file << "|Function|Signature|" << std::endl;
						file << "|---|---|" << std::endl;
					}

					if ( patterns.insert( pattern ).second ) {
						file << util::str::ssprintf( "|%s|`%s`|", name.c_str( ), pattern.c_str( ) ) << std::endl;

						printf( "[+] %s: %d/%d\r", module.name, patterns.size( ), addrs.size( ) );
					}
				}
			}

			count += patterns.size( );

			printf( "[+] %s: %d/%d (DONE)\n", module.name, patterns.size( ), addrs.size( ) );
		}

		file.close( );

		printf( "[+] dumped %d signatures to \"signatures.md\".\n", count );
	}

	/*
	 * abort dumping process
	 */
	static void abort( ) {
		g_aborted = true;
	}

	/*
	 * check if runnning
	 */
	static bool is_running( ) {
		return !g_aborted;
	}
};
