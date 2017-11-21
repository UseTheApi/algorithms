cmake_minimum_required (VERSION 2.6)
project (stack_queue)

add_definitions(-std=c++11)

include_directories(include)
include_directories(../../..)

add_executable(stack_queue main.cpp)
add_executable(stack_queue_test test.cpp)
