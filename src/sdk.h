#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <cstdint>

namespace sdk {
	template < typename t >
	t *get_interface( const char *module_name, const char *interface_name ) {
		using create_interface_fn = t *( * ) ( const char *, int * );
		const auto fn = ( create_interface_fn ) GetProcAddress( GetModuleHandleA( module_name ), "CreateInterface" );

		if ( fn ) {
			auto result = fn( interface_name, nullptr );

			if ( !result )
				return nullptr;

			return result;
		}

		return nullptr;
	}

	class d_variant;
	class recv_table;
	class recv_prop;
	class c_recv_proxy_data;

	enum send_prop_type {
		_int = 0,
		_float,
		_vec,
		_vec_xy,
		_string,
		_array,
		_data_table,
		_int_64,
	};
	class d_variant {
	public:
		union {
			float m_float;
			long m_int;
			char *m_string;
			void *m_data;
			float m_vector[ 3 ];
			__int64 m_int64;
		};
		send_prop_type type;
	};
	class c_recv_proxy_data {
	public:
		const recv_prop *recv_prop;
		d_variant value;
		int element_index;
		int object_id;
	};
	class recv_prop {
	public:
		char *prop_name;
		send_prop_type prop_type;
		int prop_flags;
		int buffer_size;
		int is_inside_of_array;
		const void *extra_data_ptr;
		recv_prop *array_prop;
		void *array_length_proxy;
		void *proxy_fn;
		void *data_table_proxy_fn;
		recv_table *data_table;
		int offset;
		int element_stride;
		int elements_count;
		const char *parent_array_prop_name;
	};
	class recv_table {
	public:
		recv_prop *props;
		int props_count;
		void *decoder_ptr;
		char *table_name;
		bool is_initialized;
		bool is_in_main_list;
	};

	class c_client_class {
	public:
		void *create_fn;
		void *create_event_fn;
		char *network_name;
		recv_table *recvtable_ptr;
		c_client_class *next_ptr;
		int class_id;
	};

	class i_client {
	private:
		virtual void u0( ) = 0;
		virtual void u1( ) = 0;
		virtual void u2( ) = 0;
		virtual void u3( ) = 0;
		virtual void u4( ) = 0;
		virtual void u5( ) = 0;
		virtual void u6( ) = 0;
		virtual void u7( ) = 0;

	public:
		virtual c_client_class *get_all_classes( ) = 0;
	};

	enum fieldtype_t {
		FIELD_VOID = 0,              // No type or value
		FIELD_FLOAT,                 // Any floating point value
		FIELD_STRING,                // A string ID (return from ALLOC_STRING)
		FIELD_VECTOR,                // Any vector, QAngle, or AngularImpulse
		FIELD_QUATERNION,            // A quaternion
		FIELD_INTEGER,               // Any integer or enum
		FIELD_BOOLEAN,               // boolean, implemented as an int, I may use this as a hint for compression
		FIELD_SHORT,                 // 2 byte integer
		FIELD_CHARACTER,             // a byte
		FIELD_COLOR32,               // 8-bit per channel r,g,b,a (32bit color)
		FIELD_EMBEDDED,              // an embedded object with a datadesc, recursively traverse and embedded class/structure based on an additional typedescription
		FIELD_CUSTOM,                // special type that contains function pointers to it's read/write/parse functions
		FIELD_CLASSPTR,              // CBaseEntity *
		FIELD_EHANDLE,               // Entity handle
		FIELD_EDICT,                 // edict_t *
		FIELD_POSITION_VECTOR,       // A world coordinate (these are fixed up across level transitions automagically)
		FIELD_TIME,                  // a floating point time (these are fixed up automatically too!)
		FIELD_TICK,                  // an integer tick count( fixed up similarly to time)
		FIELD_MODELNAME,             // Engine string that is a model name (needs precache)
		FIELD_SOUNDNAME,             // Engine string that is a sound name (needs precache)
		FIELD_INPUT,                 // a list of inputed data fields (all derived from CMultiInputVar)
		FIELD_FUNCTION,              // A class function pointer (Think, Use, etc)
		FIELD_VMATRIX,               // a vmatrix (output coords are NOT worldspace)
		FIELD_VMATRIX_WORLDSPACE,    // A VMatrix that maps some local space to world space (translation is fixed up on level transitions)
		FIELD_MATRIX3X4_WORLDSPACE,  // matrix3x4_t that maps some local space to world space (translation is fixed up on level transitions)
		FIELD_INTERVAL,              // a start and range floating point interval ( e.g., 3.2->3.6 == 3.2 and 0.4 )
		FIELD_MODELINDEX,            // a model index
		FIELD_MATERIALINDEX,         // a material index (using the material precache string table)
		FIELD_VECTOR2D,              // 2 floats
		FIELD_TYPECOUNT,             // MUST BE LAST
	};

	enum {
		TD_OFFSET_NORMAL = 0,
		TD_OFFSET_PACKED = 1,
		TD_OFFSET_COUNT,
	};

	struct datamap_t;

	struct typedescription_t {
		fieldtype_t field_type;
		const char *field_name;
		int field_offset;
		unsigned short field_size;
		short flags;
		const char *external_name;
		void *save_restore_ops;
		void *input_func;
		datamap_t *td;
		int field_size_in_bytes;
		struct typedescription_t *override_field;
		int override_count;
		float field_tolerance;
		int flat_offset[ TD_OFFSET_COUNT ];
		unsigned short flat_group;
	};

	struct datamap_t {
		typedescription_t *data_desc;
		int data_num_fields;
		char const *data_class_name;
		datamap_t *base_map;
		int packed_size;
		void *optimized_data_map;
	};
}  // namespace sdk
