cmake_minimum_required (VERSION 2.8.11)
project (binary_search_tree)

add_definitions(-std=c++11)

include_directories($ENV{algorithms}/trees/binary_search_tree/implementation/include)
include_directories(include)

add_executable(binary_search_tree main.cpp)

