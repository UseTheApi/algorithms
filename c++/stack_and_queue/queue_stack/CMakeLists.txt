cmake_minimum_required (VERSION 2.6)
project (queue_stack)

add_definitions(-std=c++11)

include_directories(include)
include_directories(../../..)

add_executable(queue_stack main.cpp)
add_executable(queue_stack_test test.cpp)
