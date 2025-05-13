# cross-compilation

My template for cross compiling C++ projects

## Dependencies

- CMake (version 3.22 or higher)
- C++ compiler with C++23 support
  - Linux: Clang++ (recommended)
  - Windows: MinGW-w64 for windows compilation
- C++ standard library with experimental support (`libstdc++exp`)

## Build Instructions

### Linux

`mkdir -p build &&
cd build &&
cmake .. &&
cmake --build .`

### Windows

`mkdir -p build &&
cd build &&
cmake -DCMAKE_TOOLCHAIN_FILE=../toolchain-mingw64.cmake .. &&
cmake --build .`
