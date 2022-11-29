cmake_minimum_required(VERSION 3.21)
project(cmake_study)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)

target_link_libraries(my_src my_math)
# 自定义一些命令pwd
add_custom_target(my-pwd
        pwd
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        )
# 起别名SRC_FILE
set(SRC_FILE
        "src/include/add.h"
        "src/main.cpp"
        )
# 自定义打包文件命令
add_custom_target(
        zip-src
        zip src.zip ${SRC_FILE}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        )
# 安装 make install
# 设置安装路径
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)
install(TARGETS my_math LIBRARY DESTINATION lib)
install(FILES ${PROJECT_SOURCE_DIR}/src/include/add.h  DESTINATION include)


