cmake_minimum_required (VERSION 2.8.11)
project (weighted_k_tree)

add_definitions(-std=c++11)

include_directories($ENV{algorithms}/linked_list/include)
include_directories(include)

add_executable(weighted_k_tree main.cpp)
