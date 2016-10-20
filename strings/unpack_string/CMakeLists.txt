cmake_minimum_required (VERSION 2.6)
project (unpack_string)

add_definitions(-std=c++11)

include_directories(include)
include_directories(src)

add_executable(unpack_string src/unpack_string.cpp main.cpp)
