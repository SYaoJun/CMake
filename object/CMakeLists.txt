cmake_minimum_required(VERSION 3.16)
project(main)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(mid)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE internal_add)