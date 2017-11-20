cmake_minimum_required (VERSION 2.6)
project (queue_linked_list)

add_definitions(-std=c++11)

include_directories(include)
include_directories(../../..)

add_executable(queue_linked_list main.cpp)
add_executable(queue_linked_list_test test.cpp)
