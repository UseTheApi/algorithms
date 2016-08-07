cmake_minimum_required (VERSION 2.6)
project (sorting)

add_definitions(-std=c++11)

add_executable(sorting selection_sort.cpp main.cpp)
