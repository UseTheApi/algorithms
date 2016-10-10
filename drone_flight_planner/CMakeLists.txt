cmake_minimum_required (VERSION 2.6)
project (drone_flight_planner)

add_definitions(-std=c++11)

add_executable(drone_flight_planner drone_flight_planner.cpp main.cpp)
