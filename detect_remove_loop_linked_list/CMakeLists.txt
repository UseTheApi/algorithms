cmake_minimum_required (VERSION 2.8.11)
project (detect_remove_loop)

add_definitions(-std=c++11)

# set(PROJECT_LINK_LIBS liblinked_list.a)
# link_directories(/Users/alenalifar/Documents/algorithms/linked_list/build)


include_directories(/Users/alenalifar/Documents/algorithms/linked_list/include)
include_directories(include)

add_executable(detect_remove_loop main.cpp)
target_link_libraries(detect_remove_loop ${PROJECT_LINK_LIBS})
