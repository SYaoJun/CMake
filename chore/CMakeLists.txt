cmake_minimum_required(VERSION 3.16)
project(chore)
set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SRC_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp")


foreach (test_source ${SRC_FILES})
    get_filename_component(test_filename ${test_source} NAME)
    string(REPLACE ".cpp" "" test_name ${test_filename})
    message(STATUS, "exec = ${test_name}")
    add_executable(${test_name} EXCLUDE_FROM_ALL ${test_source})
endforeach ()
