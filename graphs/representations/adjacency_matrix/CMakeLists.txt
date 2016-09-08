cmake_minimum_required (VERSION 2.6)
project (adjacency_matrix)

add_definitions(-std=c++11)

include_directories(include)

add_executable(adjacency_matrix main.cpp)
