cmake_minimum_required (VERSION 2.8.11)
project (alien_alphabet)

add_definitions(-std=c++11)

include_directories($ENV{algorithms}/linked_list/implementation/include)
include_directories($ENV{algorithms}/graphs/representations/adjacency_lists/include)
include_directories($ENV{algorithms}/graphs/traversals/breadth_first_search/include)
include_directories($ENV{algorithms}/graphs/application/dfs_application/edge_classification/include)
include_directories($ENV{algorithms}/graphs/application/dfs_application/topological_sort/include)
include_directories(include)

add_executable(alien_alphabet main.cpp)
