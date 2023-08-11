cmake_minimum_required(VERSION 3.16)
project(duckdb_test)
set(CMAKE_CXX_STANDARD 17)

# duckdb header
include_directories(/Users/yaojun/MyInstall/duckdb_install/usr/local/include)
# duckdb static library
find_library(DB_LIBS
        NAMES duckdb
        PATHS /Users/yaojun/MyInstall/duckdb_install/usr/local/lib
        REQUIRED)


add_executable(duckdb_test main.cpp)
# link static library
target_link_libraries(duckdb_test ${DB_LIBS})