cmake_minimum_required(VERSION 3.10)

project(Tutorial VERSION 1.0)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

add_executable(game src/main.cxx)

target_include_directories(game 
  "${CMAKE_SOURCE_DIR}/include" 
  "${CMAKE_SOURCE_DIR}/src"}

