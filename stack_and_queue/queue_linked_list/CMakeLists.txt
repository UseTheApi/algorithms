cmake_minimum_required (VERSION 2.6)
project (queue_linked_list)

add_definitions(-std=c++11)

# include_directories($ENV{algorithms}/stack_and_queue/queue_linked_list/include)
include_directories(include)

add_executable(queue_linked_list main.cpp)
