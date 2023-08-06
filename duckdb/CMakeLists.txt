cmake_minimum_required(VERSION 3.16)
project(duckdb_test)
set(CMAKE_CXX_STANDARD 17)

# 头文件目录
include_directories(/Users/yaojun/MyInstall/duckdb_install/usr/local/include)

# 找动态库
link_directories(
    /Users/yaojun/MyInstall/duckdb_install/usr/local/lib
)
add_executable(duckdb_test main.cpp)
# 链接找到的动态库
target_link_libraries(duckdb_test duckdb)