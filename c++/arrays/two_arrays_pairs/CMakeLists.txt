cmake_minimum_required (VERSION 2.6)
project (two_arrays_pairs)

add_definitions(-std=c++11)

include_directories(include)
include_directories(src)

add_executable(two_arrays_pairs src/two_arrays_pairs.cpp main.cpp)
