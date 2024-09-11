cmake_minimum_required(VERSION 3.13)
project(MyProject)


add_subdirectory(lib)
add_executable(test_executable main.cpp)


target_link_libraries(test_executable PRIVATE mylib)
