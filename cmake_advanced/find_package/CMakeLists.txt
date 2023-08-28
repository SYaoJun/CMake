cmake_minimum_required(VERSION 3.16)

project(leveldb_test)
set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
find_package(leveldb REQUIRED)
add_executable(test main.cpp)

if(LEVELDB_FOUND_)
    target_include_directories(test PRIVATE ${LEVELDB_INCLUDES_})
    target_link_libraries(test ${LEVELDB_LIBRARY_} pthread)
else(LEVELDB_FOUND_)
    message(FATAL_ERROR "library not found")
endif(LEVELDB_FOUND_)
