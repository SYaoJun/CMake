cmake_minimum_required(VERSION 3.16)
project(add_custom_target_test)
set(CMAKE_CXX_STANDARD 17)

add_executable(add_custom_target_test main.cpp)
add_custom_target(run_test COMMAND cp ../README.md README.md.bak)
add_dependencies(run_test add_custom_target_test)