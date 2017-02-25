cmake_minimum_required (VERSION 2.8.11)
project (a_shortest_path)

add_definitions(-std=c++11)

include_directories($ENV{algorithms}/linked_list/implementation/include)
include_directories($ENV{algorithms}/graphs/representations/adjacency_lists/include)
include_directories($ENV{algorithms}/graphs/traversals/breadth_first_search/include)
include_directories(include)

add_executable(a_shortest_path main.cpp)
