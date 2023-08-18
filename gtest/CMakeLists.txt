cmake_minimum_required(VERSION 3.16)
project(gtest_test)
set(CMAKE_CXX_STANDARD 17)


include_directories(/Users/yaojun/MyInstall/gtest_install/include)

find_library(LIBS
        NAMES gtest_main 
        PATHS /Users/yaojun/MyInstall/gtest_install/lib
        REQUIRED)
find_library(_LIBS
        NAMES gtest 
        PATHS /Users/yaojun/MyInstall/gtest_install/lib
        REQUIRED)
add_executable(gtest_test gtest_test.cpp)
# link static library
target_link_libraries(gtest_test ${_LIBS} ${LIBS})