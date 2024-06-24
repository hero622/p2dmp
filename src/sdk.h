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
}  // namespace sdk
