# win32 window

Created a blue window using the WIN32 API. You can either use
the CoolWindow function or create a custom_window object defined
in the custom_window.h file. I don't know what the benefit of creating a window class is, but I'm sure I'll find out later once I have to use this fucking thing.

## Dependencies

- CMake (version 3.22 or higher)
- Windows: MinGW-w64 for windows compilation

### Build instructions for linux users

`mkdir -p build &&
cd build &&
cmake -DCMAKE_TOOLCHAIN_FILE=../toolchain-mingw64.cmake .. &&
cmake --build .`
