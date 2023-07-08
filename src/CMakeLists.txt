add_subdirectory(libhello)
# 包含头文件路径
include_directories(${PROJECT_SOURCE_DIR}/include)

set(SRC_FILE main.cpp)
set(TEST_FILE simple_test.cpp)
# 可执行文件1
add_executable(MY_SRC ${SRC_FILE})
target_link_libraries(MY_SRC hello)

# 可执行文件2
add_executable(MY_TEST ${TEST_FILE})
target_link_libraries(MY_TEST gtest_main hello)