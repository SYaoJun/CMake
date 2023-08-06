cmake_minimum_required(VERSION 3.15)
project(MyExample)
set(CMAKE_CXX_STANDARD 17)
find_package(Arrow REQUIRED)
 
include_directories(/usr/local/include)

# 找动态库
link_directories(
    /usr/local/lib/
)
add_executable(MyExample main.cpp)
 
target_link_libraries(MyExample Arrow::arrow_shared)
 
