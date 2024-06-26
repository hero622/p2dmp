#include "classes.h"
#include "interfaces.h"
#include "signatures.h"

#include <iostream>

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
		signatures::dump( );
		break;
	case 2:
		classes::dump( );
		break;
	case 3:
		interfaces::dump( );
		break;
	}

	/* ==== exit ==== */
	printf( "[-] exiting in 3 seconds...\n" );

	signatures::abort( );

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
	while ( signatures::is_running( ) ) {
		/* dont listen to keypress while tabbed out */
		HWND hwnd = GetConsoleWindow( );
		if ( GetAsyncKeyState( VK_ESCAPE ) && GetForegroundWindow( ) == hwnd ) {
			signatures::abort( );
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
