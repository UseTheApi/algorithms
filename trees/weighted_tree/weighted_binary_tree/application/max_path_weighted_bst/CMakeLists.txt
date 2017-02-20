cmake_minimum_required (VERSION 2.8.11)
project (max_path_wbst)

add_definitions(-std=c++11)

include_directories($ENV{algorithms}/trees/weighted_tree/weighted_binary_tree/implementation/include)
include_directories($ENV{algorithms}/stack_and_queue/queue_linked_list/include)
include_directories(include)

add_executable(max_path_wbst main.cpp)
