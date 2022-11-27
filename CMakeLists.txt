cmake_minimum_required(VERSION 3.21)
project(cmake_study)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)

target_link_libraries(my_src my_math)

# 安装 make install
# 设置安装路径
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)
install(TARGETS my_math LIBRARY DESTINATION lib)
install(FILES ${PROJECT_SOURCE_DIR}/src/include/add.h  DESTINATION include)


