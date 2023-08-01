cmake_minimum_required(VERSION 3.16)
project(catch_v3)
set(CMAKE_CXX_STANDARD 14)
include_directories(/Users/yaojun/MyInstall/catch_install/include)
FIND_LIBRARY(CATCH2_LIBS Catch2 /Users/yaojun/MyInstall/catch_install/lib NO_DEFAULT_PATH)
FIND_LIBRARY(CATCH2MAIN_LIBS Catch2Main /Users/yaojun/MyInstall/catch_install/lib NO_DEFAULT_PATH)
# 全部可执行文件都链接这些静态库
# link_libraries(
#     "/Users/yaojun/MyInstall/catch_install/lib/libCatch2.a"
#     "/Users/yaojun/MyInstall/catch_install/lib/libCatch2Main.a"
# )
add_executable(catch_v3 hello.cpp)
#find_library(CATCH_LIB Catch2 /Users/yaojun/MyInstall/catch_install/lib)
target_link_libraries(catch_v3 ${CATCH2_LIBS} ${CATCH2MAIN_LIBS})