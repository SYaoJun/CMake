cmake_minimum_required(VERSION 3.16)
project(main)
set(CMAKE_CXX_STANDARD 17)
set(VIP "" CACHE STRING "This is a cached variable.")
if(VIP STREQUAL "")
message(SEND_ERROR "VIP must be not empty.")
endif()

add_executable(main main.cpp)
message("C++ compiler flags: ${CMAKE_CXX_FLAGS}")
# 设置编译时的宏定义
target_compile_options(main
                       PUBLIC -W -Wall -Wextra -pedantic -pedantic-errors)
target_compile_definitions(main
    INTERFACE
    VIP="${VIP}"
)