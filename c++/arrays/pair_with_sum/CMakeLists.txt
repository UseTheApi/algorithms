cmake_minimum_required (VERSION 2.6)
project (pair_with_sum)

add_definitions(-std=c++11)

include_directories(include)
include_directories(src)

add_executable(pair_with_sum src/pair_with_sum.cpp main.cpp)
