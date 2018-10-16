#include <stdio.h>
#include "library.h"
// https://github.com/ruslo/polly/issues/153
// sudo apt-get install mingw-w64 g++-mingw-w64
// sudo apt install wine-stable
// IntelliJ cmake options: -DCMAKE_TOOLCHAIN_FILE=toolchain-mingw64.cmake
// wine cmake-build-debug/ctest1.exe

int main() {
    printf("Hello, World!\n");
    hello_lib();
    return 0;
}