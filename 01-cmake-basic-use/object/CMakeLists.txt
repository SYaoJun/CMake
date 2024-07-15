cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 添加包含目录
include_directories(${CMAKE_SOURCE_DIR}/include)

# 添加对象库
add_library(my_object_lib OBJECT src/my_lib.cpp)

# 添加静态库，并将对象库链接到静态库
add_library(my_static_lib STATIC $<TARGET_OBJECTS:my_object_lib>)

# 添加动态库，并将对象库链接到动态库
add_library(my_shared_lib SHARED $<TARGET_OBJECTS:my_object_lib>)

# 添加可执行文件，并将对象库链接到可执行文件
add_executable(my_executable src/main.cpp $<TARGET_OBJECTS:my_object_lib>)

