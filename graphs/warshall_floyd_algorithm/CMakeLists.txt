cmake_minimum_required (VERSION 2.6)
project (warshall_floyd_algorithm)

add_definitions(-std=c++11)

add_executable(warshall_floyd_algorithm warshall_algorithm_dp.cpp floyd_algorithm_dp.cpp main.cpp)
