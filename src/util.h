#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <psapi.h>
#include <string>
#include <vector>

#pragma warning( disable : 4996 );

#define LOG_TIMESTAMP( )                                                                                                                   \
	{                                                                                                                                         \
		time_t now = time( 0 );                                                                                                                  \
		tm *gmtm = gmtime( &now );                                                                                                               \
		char buf[ 80 ];                                                                                                                          \
		strftime( buf, sizeof( buf ), "%d/%m/%Y at %X", gmtm );                                                                                  \
		file << util::str::ssprintf( "This dump was generated using [p2dmp](https://github.com/hero622/p2dmp) on %s (UTC).", buf ) << std::endl; \
	}

namespace util {
	namespace str {
		std::string ssprintf( const char *fmt, ... ) {
			va_list ap1, ap2;
			va_start( ap1, fmt );
			va_copy( ap2, ap1 );
			size_t sz = vsnprintf( NULL, 0, fmt, ap1 ) + 1;
			va_end( ap1 );
			char *buf = ( char * ) malloc( sz );
			vsnprintf( buf, sz, fmt, ap2 );
			va_end( ap2 );
			std::string str( buf );
			free( buf );
			return str;
		}
	}  // namespace str

	namespace mem {
		struct module_info_t {
			char name[ MAX_PATH ];
			void *base;
		};
		std::vector< module_info_t > dump_modules( ) {
			std::vector< module_info_t > result;

			HMODULE mods[ 1024 ];
			HANDLE proc = GetCurrentProcess( );
			DWORD cb_needed;
			if ( EnumProcessModules( proc, mods, sizeof( mods ), &cb_needed ) ) {
				for ( unsigned int i = 3; i < ( cb_needed / sizeof( HMODULE ) ); ++i ) {
					char sz_mod_name[ MAX_PATH ];

					if ( GetModuleFileNameA( mods[ i ], sz_mod_name, sizeof( sz_mod_name ) ) ) {
						auto info = MODULEINFO( );

						if ( !GetModuleInformation( proc, mods[ i ], &info, sizeof( info ) ) )
							continue;

						auto name = std::string( sz_mod_name );
						auto index = name.find_last_of( "\\/" );
						name = name.substr( index + 1, name.length( ) - index );

						module_info_t mod_info;

						std::snprintf( mod_info.name, sizeof( mod_info.name ), "%s", name.c_str( ) );
						mod_info.base = info.lpBaseOfDll;

						result.push_back( mod_info );
					};
				}
			}

			return result;
		}

		std::uint8_t *get_import_addr( void *module_handle, const char *import_dll, const char *symbol ) {
			auto dos_header = reinterpret_cast< PIMAGE_DOS_HEADER >( module_handle );
			auto nt_headers = reinterpret_cast< PIMAGE_NT_HEADERS >( reinterpret_cast< std::uint8_t * >( module_handle ) + dos_header->e_lfanew );

			auto imports = reinterpret_cast< PIMAGE_IMPORT_DESCRIPTOR >( reinterpret_cast< std::uint8_t * >( dos_header ) + nt_headers->OptionalHeader.DataDirectory[ IMAGE_DIRECTORY_ENTRY_IMPORT ].VirtualAddress );

			for ( int i = 0; imports[ i ].Characteristics != 0; ++i ) {
				auto dll_name = reinterpret_cast< char * >( reinterpret_cast< std::uint8_t * >( dos_header ) + imports[ i ].Name );

				if ( _strcmpi( dll_name, import_dll ) == 0 ) {
					PIMAGE_THUNK_DATA thunk;
					PIMAGE_THUNK_DATA orig_thunk;

					if ( !imports[ i ].FirstThunk || !imports[ i ].OriginalFirstThunk )
						return nullptr;

					thunk = reinterpret_cast< PIMAGE_THUNK_DATA >( reinterpret_cast< std::uint8_t * >( dos_header ) + imports[ i ].FirstThunk );
					orig_thunk = reinterpret_cast< PIMAGE_THUNK_DATA >( reinterpret_cast< std::uint8_t * >( dos_header ) + imports[ i ].OriginalFirstThunk );

					for ( ; orig_thunk->u1.Function != NULL; orig_thunk++, thunk++ ) {
						if ( orig_thunk->u1.Ordinal & IMAGE_ORDINAL_FLAG )
							continue;

						PIMAGE_IMPORT_BY_NAME import = reinterpret_cast< PIMAGE_IMPORT_BY_NAME >( reinterpret_cast< std::uint8_t * >( dos_header ) + orig_thunk->u1.AddressOfData );

						if ( strcmp( symbol, ( char * ) import->Name ) == 0 ) {
							return reinterpret_cast< std::uint8_t * >( thunk );
						}
					}
				}
			}
		}

		std::vector< std::uint8_t * > multi_scan( void *module_handle, const char *signature ) noexcept {
			std::vector< std::uint8_t * > result;

			static auto pattern_to_byte = []( const char *pattern ) {
				auto bytes = std::vector< int > { };
				auto start = const_cast< char * >( pattern );
				auto end = const_cast< char * >( pattern ) + std::strlen( pattern );

				for ( auto current = start; current < end; ++current ) {
					if ( *current == '?' ) {
						++current;

						if ( *current == '?' )
							++current;

						bytes.push_back( -1 );
					} else {
						bytes.push_back( std::strtoul( current, &current, 16 ) );
					}
				}
				return bytes;
			};

			auto dos_header = reinterpret_cast< PIMAGE_DOS_HEADER >( module_handle );
			auto nt_headers = reinterpret_cast< PIMAGE_NT_HEADERS >( reinterpret_cast< std::uint8_t * >( module_handle ) + dos_header->e_lfanew );

			auto size_of_image = nt_headers->OptionalHeader.SizeOfImage;
			auto pattern_bytes = pattern_to_byte( signature );
			auto scan_bytes = reinterpret_cast< std::uint8_t * >( module_handle );

			auto s = pattern_bytes.size( );
			auto d = pattern_bytes.data( );

			for ( auto i = 0ul; i < size_of_image - s; ++i ) {
				bool found = true;

				for ( auto j = 0ul; j < s; ++j ) {
					if ( scan_bytes[ i + j ] != d[ j ] && d[ j ] != -1 ) {
						found = false;
						break;
					}
				}
				if ( found )
					result.push_back( &scan_bytes[ i ] );
			}

			return result;
		}

		std::vector< std::uint8_t * > multi_scan( void *module_handle, std::uint8_t *pattern_bytes, std::size_t pattern_size ) noexcept {
			std::vector< std::uint8_t * > result;

			auto dos_header = reinterpret_cast< PIMAGE_DOS_HEADER >( module_handle );
			auto nt_headers = reinterpret_cast< PIMAGE_NT_HEADERS >( reinterpret_cast< std::uint8_t * >( module_handle ) + dos_header->e_lfanew );

			auto size_of_image = nt_headers->OptionalHeader.SizeOfImage;
			auto scan_bytes = reinterpret_cast< std::uint8_t * >( module_handle );

			auto s = pattern_size;
			auto d = pattern_bytes;

			for ( auto i = 0ul; i < size_of_image - s; ++i ) {
				bool found = true;

				for ( auto j = 0ul; j < s; ++j ) {
					if ( scan_bytes[ i + j ] != d[ j ] && d[ j ] != -1 ) {
						found = false;
						break;
					}
				}
				if ( found )
					result.push_back( &scan_bytes[ i ] );
			}

			return result;
		}
	}  // namespace mem
}  // namespace util
