cmake_minimum_required (VERSION 2.8.11)
project (max_weighted_path)

add_definitions(-std=c++11)

include_directories($ENV{algorithms}/trees/weighted_tree/k-ary_weighted_tree/implementation/include)
include_directories(include)

add_executable(max_weighted_path main.cpp)
