#pragma once

#include "sdk.h"
#include "util.h"

#include <fstream>
#include <set>

class interfaces {
private:
	struct interface_reg_t {
		BYTE createfn[ 4 ];
		const char *name;
		interface_reg_t *next;
	};

public:
	/*
	 * dump all interfaces
	 */
	static void dump( ) {
		printf( "[+] dumping interfaces...\n" );

		/* open file for writing */
		std::ofstream file;
		file.open( "interfaces.md" );
		file << "# Interfaces" << std::endl;
		LOG_TIMESTAMP( );

		/* ==== loop through all interfaces from all modules ==== */
		size_t count = 0;
		for ( const auto &module : util::mem::dump_modules( ) ) {
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

				interface_reg_t *reg = **( interface_reg_t *** ) ( var04 + 0x6 );
				if ( !reg ) continue;

				file << util::str::ssprintf( "## %s", module.name ) << std::endl;
				file << "|Module|Interface|" << std::endl;
				file << "|---|---|" << std::endl;

				/* filter out unique */
				std::set< const char * > ifaces;
				for ( interface_reg_t *cur = reg; cur; cur = cur->next ) {
					ifaces.insert( cur->name );
				}
				for ( const auto &iface : ifaces ) {
					file << util::str::ssprintf( "|%s|%s|", module.name, iface ) << std::endl;

					++count;
				}
			}
		}

		file.close( );

		printf( "[+] dumped %d interfaces to \"interfaces.md\".\n", count );
	}
};
