 cmake_minimum_required(VERSION 3.16)
 project(leveldb_test)
 set(CMAKE_CXX_STANDARD 14)

# include_directories(/usr/local/include)
#
# find_library(LIBS  leveldb /usr/local/lib)

 find_library(DB_LIBS NAMES leveldb PATHS /usr/local/ REQUIRED)
 include_directories(/usr/local/include/)
 add_executable(leveldb_test test.cpp)

 target_link_libraries(leveldb_test ${LIBS})
