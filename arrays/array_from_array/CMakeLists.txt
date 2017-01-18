cmake_minimum_required (VERSION 2.6)
project (array_from_array)

add_definitions(-std=c++11)

include_directories(include)
include_directories(src)

add_executable(array_from_array src/array_from_array.cpp main.cpp)
