cmake_minimum_required(VERSION 3.16)
project(main)
set(CMAKE_CXX_STANDARD 17)

find_package(Threads)
add_executable(main main.cpp)
target_link_libraries(main Threads::Threads)