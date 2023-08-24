 cmake_minimum_required(VERSION 3.16)
 project(picobench_test)
 set(CMAKE_CXX_STANDARD 17)
 set(CMAKE_BUILD_TYPE "relase")
 # test1
 add_executable(picobench_test picobench.hpp picobench_test.cpp)