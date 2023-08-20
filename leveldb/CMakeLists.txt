 cmake_minimum_required(VERSION 3.16)
 project(leveldb_test)
 set(CMAKE_CXX_STANDARD 17)
 set(CMAKE_BUILD_TYPE "Debug")
 include_directories(/Users/yaojun/MyInstall/leveldb_install/include)
 find_library(LIBS leveldb PATH /Users/yaojun/MyInstall/leveldb_install/lib REQUIRE)

# Linux上一定要加pthread否则链接不上
 add_executable(leveldb_test leveldb_test.cpp)
 target_link_libraries(leveldb_test ${LIBS} pthread)

