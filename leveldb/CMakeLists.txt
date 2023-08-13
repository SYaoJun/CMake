 cmake_minimum_required(VERSION 3.16)
 project(leveldb_test)
 set(CMAKE_CXX_STANDARD 14)

# include_directories(/usr/local/include)
#
# find_library(LIBS  leveldb /usr/local/lib)
#
# CMAKE_INSTALL_PREFIX(/Users/yaojun/db/CMakeTutorial)
# if(NOT CMAKE_BUILD_TYPE)
#    set(CMAKE_BUILD_TYPE RELESE FORCE)
# endif()
# message(STATUS "Build type set to ${CMAKE_BUILD_TYPE}")
# find_library(DB_LIBS NAMES leveldb PATHS /usr/local/ REQUIRED)
# include_directories(/usr/local/include/)
# add_executable(leveldb_test test.cpp)
#
# target_link_libraries(leveldb_test ${LIBS})


# add_executable(ra RA.cpp)
add_executable(cs2310 cs2310.cpp)