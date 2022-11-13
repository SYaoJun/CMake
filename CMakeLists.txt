cmake_minimum_required(VERSION 3.21)
project(cpp_daily)
# 设置CPP标准
set(CMAKE_CXX_STANDARD 14)
# 添加子目录
add_subdirectory(math)
set(INCL ./include)
# 生成可执行文件
add_executable(cpp_daily main.cpp)
# 链接库文件
target_link_libraries(cpp_daily mysqrt)
# 设置为gdb模式
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_INSTALL_PREFIX ../output)
# 指定安装路径
install (TARGETS cpp_daily DESTINATION bin)
install (FILES "${INCL}/hello.h" DESTINATION include)