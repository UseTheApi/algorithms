cmake_minimum_required (VERSION 2.6)
project (max_burglary)

add_definitions(-std=c++11)

include_directories(include)
include_directories(src)

add_executable(max_burglary src/max_burglary.cpp main.cpp)
