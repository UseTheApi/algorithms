cmake_minimum_required (VERSION 2.8.11)
project (equal_trees)

add_definitions(-std=c++11)

include_directories($ENV{algorithms}/trees/binary_search_tree/implementation/bst/include)
include_directories($ENV{algorithms}/stack_and_queue/queue_linked_list/include)
include_directories(include)

add_executable(equal_trees main.cpp)

