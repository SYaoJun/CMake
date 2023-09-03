cmake_minimum_required(VERSION 3.16)
project(main)
set(CMAKE_CXX_STANDARD 14)

find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
  message(STATUS "Set up ccache ...")
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif()

add_executable(main hello.cpp)
target_precompile_headers(main PRIVATE world.h)
