cmake_minimum_required (VERSION 2.6)
project (products_in_array)

add_definitions(-std=c++11)

include_directories(".")

add_executable(products_in_array product_all_num_except_itself.cpp main.cpp)
