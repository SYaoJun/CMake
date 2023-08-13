cmake_minimum_required(VERSION 3.16)
project(chore)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE RELESE)

#file(GLOB_RECURSE SRC_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp")
#
#
#foreach (test_source ${SRC_FILES})
#    get_filename_component(test_filename ${test_source} NAME)
#    string(REPLACE ".cpp" "" test_name ${test_filename})
#    message(STATUS, "exec = ${test_name}")
#    add_executable(${test_name} EXCLUDE_FROM_ALL ${test_source})
#endforeach ()

add_executable(xxy src/game.cpp)

#set(PARENT_VAR "yaojun")
#add_subdirectory(src)
