cmake_minimum_required (VERSION 2.6)
project (pairs)

add_definitions(-std=c++11)

include_directories(".")

add_executable(pairs pairs.cpp main.cpp)
