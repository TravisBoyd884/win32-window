cmake_minimum_required(VERSION 3.22)

project(game
  VERSION "0.0.1"
  DESCRIPTION "A game about Karnaugh Maps"
  LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Compiler settings based on platform
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  # Windows-specific settings (MinGW)
  # Compiler is set in toolchain file
else()
  # Linux-specific settings
  set(CMAKE_CXX_COMPILER clang++)
endif()

add_executable(game WIN32 src/main.cxx src/custom_window.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE "-lstdc++exp")

target_compile_definitions(game PUBLIC -DNOMINMAX)  # -D removed

target_include_directories(game PRIVATE
  "${CMAKE_SOURCE_DIR}/include"
  "${CMAKE_SOURCE_DIR}/src")

