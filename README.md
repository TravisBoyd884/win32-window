# Karnaugh Maps

A game that helps you practice using [Karnaugh maps](https://en.wikipedia.org/wiki/Karnaugh_map).

## Build Instructions

### Linux

`mkdir -p build
cd build
cmake ..
cmake --build .`

### Windows

`mkdir -p build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=../toolchain-mingw64.cmake ..
cmake --build .`
