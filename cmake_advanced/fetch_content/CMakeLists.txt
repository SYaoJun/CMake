cmake_minimum_required(VERSION 3.17)
project(fetch)
set(CMAKE_CXX_STANDARD 17)

add_executable(fetch main.cpp)

# step1
include(FetchContent)
# step2 FetchContent_Declare

FetchContent_Declare(json
        GIT_REPOSITORY https://github.com/nlohmann/json.git  
        GIT_TAG v3.7.3)
# step3
# FetchContent_MakeAvailable
FetchContent_MakeAvailable(json)
# target_link_libraries

target_link_libraries(fetch PRIVATE nlohmann_json::nlohmann_json)

FetchContent_Declare(spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG v1.4.1)
FetchContent_MakeAvailable(spdlog)
target_link_libraries(fetch PRIVATE spdlog::spdlog)