cmake_minimum_required(VERSION 3.16)
project(catch_v3)
set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/local/include/)
find_library(CATCH2_LIBS Catch2 /Users/yaojun/MyInstall/catch_install/lib NO_DEFAULT_PATH)
find_library(CATCH2MAIN_LIBS Catch2Main /Users/yaojun/MyInstall/catch_install/lib NO_DEFAULT_PATH)

# hello
add_executable(catch_v3 hello.cpp)
target_link_libraries(catch_v3 ${CATCH2_LIBS} ${CATCH2MAIN_LIBS})

# bdd 
add_executable(bdd bdd.cpp)
target_link_libraries(bdd ${CATCH2_LIBS} ${CATCH2MAIN_LIBS})

# benchmark
add_executable(benchmark benchmark.cpp)
target_link_libraries(benchmark ${CATCH2_LIBS} ${CATCH2MAIN_LIBS})