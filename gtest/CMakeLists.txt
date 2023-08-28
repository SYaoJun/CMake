cmake_minimum_required(VERSION 3.16)
project(gtest_test)
set(CMAKE_CXX_STANDARD 17)

 # google test
 include(FetchContent)
 FetchContent_Declare(
         googletest
         GIT_REPOSITORY https://github.com/google/googletest.git
         GIT_TAG v1.14.0
 )
 FetchContent_MakeAvailable(googletest)

add_executable(gtest_test gtest_test.cpp)
# link static library
target_link_libraries(gtest_test gtest_main)