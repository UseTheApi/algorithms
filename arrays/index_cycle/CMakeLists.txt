cmake_minimum_required (VERSION 2.6)
project (index_cycle)

add_definitions(-std=c++11)

include_directories(include)
include_directories(src)

add_executable(index_cycle src/index_cycle.cpp main.cpp)
