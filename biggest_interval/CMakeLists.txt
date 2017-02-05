cmake_minimum_required (VERSION 2.6)
project (biggest_interval)

add_definitions(-std=c++11)

include_directories(include)
include_directories(src)

add_executable(biggest_interval src/biggest_interval.cpp main.cpp)
