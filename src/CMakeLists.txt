add_subdirectory(libhello)
# 包含头文件路径
include_directories(${PROJECT_SOURCE_DIR}/include)
# 包含静态库路径
link_directories(${PROJECT_SOURCE_DIR}/lib)

# 可执行文件1
add_executable(MY_SRC main.cpp)
target_link_libraries(MY_SRC hello)

# 可执行文件2
add_executable(MY_TEST simple_test.cpp)
target_link_libraries(MY_TEST gtest_main hello)