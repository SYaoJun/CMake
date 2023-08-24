 cmake_minimum_required(VERSION 3.16)
 project(spdlog_test)
 set(CMAKE_CXX_STANDARD 17)
 set(CMAKE_BUILD_TYPE "Debug")

 add_executable(spdlog_test spdlog_test.cpp)


include(FetchContent)
FetchContent_Declare(spdlog
        GIT_REPOSITORY https://gitee.com/roberchen/spdlog.git
        GIT_TAG v1.4.1)
FetchContent_MakeAvailable(spdlog)
target_link_libraries(spdlog_test PRIVATE spdlog::spdlog)
 

