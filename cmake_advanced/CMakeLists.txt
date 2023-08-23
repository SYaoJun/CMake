cmake_minimum_required(VERSION 3.16)
project(advanced)
set(CMAKE_CXX_STANDARD 14)

add_executable(my_app define_test.cpp)
# 宏定义开关
target_compile_definitions(my_app PRIVATE ENABLE_FEATURE_A)