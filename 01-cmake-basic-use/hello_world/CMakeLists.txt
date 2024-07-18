cmake_minimum_required(VERSION 3.16)
project(main)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(hello)

add_executable(main main.cpp)