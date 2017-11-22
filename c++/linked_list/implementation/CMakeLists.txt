cmake_minimum_required (VERSION 2.8.9)
project (linked_list C CXX)

add_definitions(-std=c++11)

include_directories(include)
include_directories(../../..)

add_executable(linked_list main.cpp)
add_executable(linked_list_test test.cpp)
