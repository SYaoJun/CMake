 cmake_minimum_required(VERSION 3.16)
 project(leveldb_test)
 set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/local/include)
find_library(LIBS  leveldb /usr/local/lib)


add_executable(leveldb_test leveldb_test.cpp)
target_link_libraries(leveldb_test ${LIBS})

