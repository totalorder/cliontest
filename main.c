#include <stdio.h>
#include <windows.h>
#include "library.h"
// https://github.com/ruslo/polly/issues/153
// sudo apt-get install mingw-w64 g++-mingw-w64
// sudo apt install wine-stable
// IntelliJ cmake options: -DCMAKE_TOOLCHAIN_FILE=toolchain-mingw64.cmake
// wine cmake-build-debug/ctest1.exe
void start_child();

int main() {
    printf("Hello, World!\n");
    hello_lib();

    start_child();

    return 0;
}

void start_child() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );

    // Start the child process.
    if( !CreateProcess( NULL,   // No module name (use command line)
                        "child.exe",        // Command line
                        NULL,           // Process handle not inheritable
                        NULL,           // Thread handle not inheritable
                        FALSE,          // Set handle inheritance to FALSE
                        0,              // No creation flags
                        NULL,           // Use parent's environment block
                        NULL,           // Use parent's starting directory
                        &si,            // Pointer to STARTUPINFO structure
                        &pi )           // Pointer to PROCESS_INFORMATION structure
            )
    {
        printf( "CreateProcess failed (%d).\n", GetLastError() );
        return;
    }

    // Wait until child process exits.
    WaitForSingleObject( pi.hProcess, INFINITE );

    // Close process and thread handles.
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );
}
