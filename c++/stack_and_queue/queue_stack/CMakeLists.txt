cmake_minimum_required (VERSION 2.6)
project (queue_stack)

add_definitions(-std=c++11)

include_directories($ENV{algorithms}/c++/stack_and_queue/stack_linked_list/include)
include_directories(include)

add_executable(queue_stack main.cpp)
