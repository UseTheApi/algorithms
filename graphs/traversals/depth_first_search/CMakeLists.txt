cmake_minimum_required (VERSION 2.8.11)
project (depth_first_search)

add_definitions(-std=c++11)

include_directories($ENV{algorithms}/linked_list/implementation/include)
include_directories($ENV{algorithms}/graphs/representations/adjacency_lists/include)
include_directories(include)

add_executable(depth_first_search main.cpp)

