add_subdirectory(libhello)
# header
include_directories(${PROJECT_SOURCE_DIR}/include)

set(SRC_FILE main.cpp)
set(TEST_FILE simple_test.cpp)
# exec
add_executable(MY_SRC ${SRC_FILE})
# link libs
target_link_libraries(MY_SRC hello)