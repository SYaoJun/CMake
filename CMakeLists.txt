# cmake至少3.16以上
cmake_minimum_required(VERSION 3.16)
# 工程名
project(cmake_study)
# 设置C++版本
set(CMAKE_CXX_STANDARD 14)
# 添加子目录
add_subdirectory(src)
add_subdirectory(third)
# 允许测试
enable_testing()
