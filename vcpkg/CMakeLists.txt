cmake_minimum_required(VERSION 3.10)
project(abc)

# 设置 vcpkg 工具链文件
set(CMAKE_TOOLCHAIN_FILE /Users/yaojun/MyInstall/vcpkg-master/scripts/buildsystems/vcpkg.cmake
    CACHE STRING "Vcpkg toolchain file")

# 添加可执行文件
add_executable(main src/main.cpp)

# 查找并链接依赖库
find_package(ZLIB REQUIRED)
find_package(fmt REQUIRED)
target_link_libraries(main PRIVATE ZLIB::ZLIB fmt::fmt)
