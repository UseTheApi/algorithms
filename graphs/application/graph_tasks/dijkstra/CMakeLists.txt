cmake_minimum_required (VERSION 2.8.11)
project (dijkstra)

add_definitions(-std=c++11)

include_directories($ENV{algorithms}/graphs/representations/weighted_graph/include)
include_directories($ENV{algorithms}/trees/binary_heap/include)
include_directories(include)

add_executable(dijkstra main.cpp)
