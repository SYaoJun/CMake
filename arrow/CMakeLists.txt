cmake_minimum_required(VERSION 3.15)
project(MyExample)

find_package(Arrow REQUIRED)

if (Arrow_FOUND)
    message("Arrow_FOUND:${Arrow_FOUND}")
    message("Arrow_version:${Arrow_VERSION}")
    message("Arrow_include:${Arrow_INCLUDE_DIR}")
    message("Arrow_library:${Arrow_LIBRARY}")
endif()

add_executable(MyExample main.cpp)

target_link_libraries(MyExample PRIVATE arrow_shared)

set(CMAKE_CXX_STANDARD 11)