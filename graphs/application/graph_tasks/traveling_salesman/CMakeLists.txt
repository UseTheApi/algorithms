cmake_minimum_required (VERSION 2.8.11)
project (traveling_salesman)

add_definitions(-std=c++11)

include_directories($ENV{algorithms}/graphs/representations/weighted_graph/include)
include_directories(include)

add_executable(traveling_salesman main.cpp)
