#pragma once

#include "sdk.h"
#include "util.h"

#include <algorithm>
#include <fstream>
#include <functional>

class classes {
private:
	struct prop_t {
		std::string name;
		int type;
		int offset;
	};
	struct class_t {
		std::string name;
		std::vector< prop_t > props;
	};
	static inline std::vector< class_t > g_classes;
	static inline class_t *g_cur_class;

	/*
	 * recursively dump all netvars
	 */
	static void dump_netvars( size_t &count ) {
		const auto client = sdk::get_interface< sdk::i_client >( "client.dll", "VClient016" );

		std::function< void( const char *, sdk::recv_table *, uint32_t ) > recursive_dump;
		recursive_dump = [ & ]( const char *baseclass, sdk::recv_table *table, uint32_t offset ) {
			for ( size_t i = 0; i < table->props_count; ++i ) {
				const auto prop = &table->props[ i ];

				/* sanity checks */
				if ( table->props_count < 3 )
					continue;

				if ( !prop || isdigit( prop->prop_name[ 0 ] ) )
					continue;

				if ( i == 0 && baseclass != g_cur_class->name ) {
					auto tmp = class_t( );
					tmp.name = baseclass;
					if ( !tmp.name.empty( ) ) {
						g_classes.push_back( tmp );
						g_cur_class = &g_classes.back( );
					}

					continue;
				}

				if ( prop->prop_type == sdk::send_prop_type::_data_table && prop->data_table && prop->data_table->table_name[ 0 ] == 'D' )
					recursive_dump( baseclass, prop->data_table, offset + prop->offset );

				prop_t custom_prop;
				custom_prop.name = prop->prop_name;
				custom_prop.type = prop->prop_type + 1;  // shift by 1, idx 0 is for unknown
				custom_prop.offset = offset + prop->offset;
				g_cur_class->props.push_back( custom_prop );

				++count;
			}
		};

		/* go through each class and dump */
		for ( auto client_class = client->get_all_classes( ); client_class; client_class = client_class->next_ptr ) {
			if ( client_class->recvtable_ptr )
				recursive_dump( client_class->network_name, client_class->recvtable_ptr, 0 );
		}
	}

	/*
	 * dump datamaps
	 */
	static void dump_datamaps( size_t &count ) {
		const auto addrs = util::mem::multi_scan( GetModuleHandleA( "client.dll" ), "C7 05 ? ? ? ? ? ? ? ? C7 05 ? ? ? ? ? ? ? ? C3 CC" );
		for ( const auto &addr : addrs ) {
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
					auto it = std::find_if( g_classes.begin( ), g_classes.end( ), [ & ]( const class_t &x ) {
						return x.name == map->data_class_name;
					} );
					if ( it != g_classes.end( ) )
						g_cur_class = &g_classes[ std::distance( g_classes.begin( ), it ) ];
					else {
						auto tmp = class_t( );
						tmp.name = map->data_class_name;
						if ( !tmp.name.empty( ) ) {
							g_classes.push_back( tmp );
							g_cur_class = &g_classes.back( );
						}
					}
				}

				prop_t custom_prop;
				custom_prop.name = prop->field_name;
				custom_prop.type = prop->field_type + 9;
				custom_prop.offset = prop->field_offset;
				g_cur_class->props.push_back( custom_prop );

				++count;
			}
		}
	}

	/*
	 * get type information like name, size
	 */
	static std::pair< const char *, size_t > get_type( prop_t *prop ) {
		/* type information */
		std::pair< const char *, size_t > types[ 40 ] {
			/* name, size */
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

		return types[ prop->type ];
	}

public:
	/*
	 * dump classes built from netvars and datamaps
	 */
	static void dump( ) {
		printf( "[+] dumping classes...\n" );

		/* open file for writing */
		std::ofstream file;
		file.open( "classes.md" );
		file << "# Classes" << std::endl;
		LOG_TIMESTAMP( );

		size_t count = 0;

		g_cur_class = new class_t( );

		dump_netvars( count );

		dump_datamaps( count );

		/* ==== write dumps to file ==== */
		for ( auto &client_class : g_classes ) {
			file << util::str::ssprintf( "## %s", client_class.name.c_str( ) ) << std::endl;
			file << util::str::ssprintf( "```cpp\nstruct %s {", client_class.name.c_str( ) ) << std::endl;

			/* sort by offset */
			std::sort( client_class.props.begin( ), client_class.props.end( ), []( const prop_t &lhs, const prop_t &rhs ) {
				return lhs.offset < rhs.offset;
			} );

			for ( size_t i = 0; i < client_class.props.size( ); ++i ) {
				const auto prop = &client_class.props[ i ];

				auto last_prop = new prop_t( );
				if ( i > 0 ) {
					last_prop = &client_class.props[ i - 1 ];

					if ( prop->offset == last_prop->offset )
						continue;
				}

				/* add alignment offset */
				int offset = prop->offset - last_prop->offset - get_type( last_prop ).second;
				if ( offset > 0 ) {
					file << util::str::ssprintf( "	char pad_%04x[%d];  // 0x%04x", prop->offset, offset, last_prop->offset + get_type( last_prop ).second ) << std::endl;
				}

				file << util::str::ssprintf( "	%s%s;  // 0x%04x", get_type( prop ).first, prop->name.c_str( ), prop->offset ) << std::endl;
			}

			file << "}\n```" << std::endl;
		}

		file.close( );

		printf( "[+] dumped %d fields to \"classes.md\".\n", count );
	}
};
