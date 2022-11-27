# cmake至少3.16以上
cmake_minimum_required(VERSION 3.16)

# 工程名叫做hello
project(hello)

# C++14
set(CMAKE_CXX_STANDARD 14)
# 生成动态库
add_library(hello SHARED ${PROJECT_SOURCE_DIR}/hello.cpp)
# 设置安装路径
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)
install(TARGETS hello LIBRARY DESTINATION lib)
install(FILES ${PROJECT_SOURCE_DIR}/hello.h  DESTINATION include)