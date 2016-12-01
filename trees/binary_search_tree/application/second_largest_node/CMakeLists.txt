cmake_minimum_required (VERSION 2.8.11)
project (second_largest_node)

add_definitions(-std=c++11)

include_directories($ENV{algorithms}/trees/binary_search_tree/implementation/bst/include)
include_directories(include)

add_executable(second_largest_node main.cpp)
