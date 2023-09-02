 cmake_minimum_required(VERSION 3.16)
 project(openmp_test)
 set(CMAKE_CXX_STANDARD 17)
 find_library(OpenMP_LIBS omp /opt/homebrew/opt/libomp/lib)
 include_directories(/opt/homebrew/opt/libomp/include)

add_executable(openmp_test openmp_test.cpp)
target_link_libraries(openmp_test ${OpenMP_LIBS})
