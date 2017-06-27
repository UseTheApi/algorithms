cmake_minimum_required (VERSION 2.6)
project (stock_prices)

add_definitions(-std=c++11)

include_directories(".")

add_executable(stock_prices max_profit_in_stock.cpp main.cpp)
