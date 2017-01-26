cmake_minimum_required (VERSION 2.6)
project (dinner_party)

add_definitions(-std=c++11)

include_directories(include)
include_directories(src)

add_executable(dinner_party src/dinner_party.cpp main.cpp)
