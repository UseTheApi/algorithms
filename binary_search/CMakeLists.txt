cmake_minimum_required (VERSION 2.6)
project (binary_search)

add_definitions(-std=c++11)

add_executable(binary_search binary_search.cpp main.cpp binary_search.hpp)
