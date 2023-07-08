> 教程里的文档是Lecture.md
# CMake
## CMake概述
- 开源
- 跨平台
- 构建C++
- 简化Makefile
## 大纲
- 快速使用
- 子目录嵌套
- 动态库
- Google Test
## 快速使用
```cmake
# cmake至少3.16以上
cmake_minimum_required(VERSION 3.16)
# 工程名
project(cmake_study)
# 设置C++版本
set(CMAKE_CXX_STANDARD 14)
# 可执行文件
add_executable(main main.cpp)
```
## 子目录嵌套
```c
add_subdirectory(libhello)
```
## 动态库
```c
add_library(hello SHARED hello.cpp hello.h)
```
