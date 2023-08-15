cmake_minimum_required(VERSION 3.16)
project(abseil_test)
set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/local/include/)
find_library(ABSEIL_LIBS absl_strings /usr/local/lib REQUIRED)


# exec
add_executable(abseil_test abseil_test.cpp)
target_link_libraries(abseil_test ${ABSEIL_LIBS})
