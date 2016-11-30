cmake_minimum_required (VERSION 2.8.11)
project (lowest_common_ancestor)

add_definitions(-std=c++11)

include_directories($ENV{algorithms}/trees/binary_search_tree/implementation/include)
include_directories(include)

add_executable(lowest_common_ancestor main.cpp)
