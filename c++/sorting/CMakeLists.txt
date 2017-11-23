cmake_minimum_required (VERSION 2.6)
project (sorting)

add_definitions(-std=c++11)

include_directories(include)
include_directories(../..)

add_executable(sorting main.cpp)
add_executable(sorting_test test.cpp)
