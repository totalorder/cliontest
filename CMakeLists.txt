cmake_minimum_required(VERSION 3.12)
project(ctest1 C)

set(CMAKE_C_STANDARD 11)

add_library(ctest2 SHARED library.c library.h)
add_executable(ctest1 main.c library.h)
target_link_libraries (ctest1 ctest2)