cmake_minimum_required (VERSION 2.8.11)
project (bst_tree)

add_definitions(-std=c++11)

include_directories(include)

add_executable(bst_tree main.cpp)
