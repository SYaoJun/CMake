cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 添加包含目录
include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(my_object_lib OBJECT src/my_lib.cpp)

add_library(my_static_lib STATIC $<TARGET_OBJECTS:my_object_lib>)

add_library(my_shared_lib SHARED $<TARGET_OBJECTS:my_object_lib>)

add_executable(my_executable src/main.cpp $<TARGET_OBJECTS:my_object_lib>)

