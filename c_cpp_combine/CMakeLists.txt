cmake_minimum_required(VERSION 3.16)
project(gtest_test)
set(CMAKE_CXX_STANDARD 17)

add_library(b SHARED b.cpp)
add_executable(my_test main.c)
target_link_libraries(my_test b)

