# cmake至少3.16以上
cmake_minimum_required(VERSION 3.16)
# 工程名
project(webserver)
set(CMAKE_CXX_STANDARD 14)
message("\n #### I love China! #### \n")
# 头文件
include_directories(${PROJECT_SRC_DIR}/include)
# 子目录
add_subdirectory(src)
# 链接
target_link_libraries(my_src my_world)
# 设置安装路径
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)
install(TARGETS my_world LIBRARY DESTINATION lib)
install(FILES src/include/world.h DESTINATION include)