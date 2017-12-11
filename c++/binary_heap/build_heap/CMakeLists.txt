cmake_minimum_required (VERSION 2.8.9)
project (build_heap C CXX)

add_definitions(-std=c++11)

include_directories(include)
include_directories(../../..)

add_executable(build_heap main.cpp)
add_executable(build_heap_test test.cpp)
