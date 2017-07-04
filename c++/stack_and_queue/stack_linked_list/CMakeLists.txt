cmake_minimum_required (VERSION 2.6)
project (stack_linked_list)

add_definitions(-std=c++11)

include_directories($ENV{algorithms}/c++/stack_and_queue/stack_linked_list/include)

add_executable(stack_linked_list main.cpp)
