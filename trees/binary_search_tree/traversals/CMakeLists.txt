cmake_minimum_required (VERSION 2.8.11)
project (bst_traversals)

add_definitions(-std=c++11)

include_directories($ENV{algorithms}/trees/binary_search_tree/implementation/bst/include)
include_directories($ENV{algorithms}/stack_and_queue/stack_linked_list/include)
include_directories($ENV{algorithms}/stack_and_queue/queue_linked_list/include)
include_directories(include)

add_executable(bst_traversals main.cpp)
