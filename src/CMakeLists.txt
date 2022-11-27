# 查找当前目录下的所有源文件，并将名称保存到 DIR_SRCS 变量
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} DIR_src_SRCS)
# 子目录
add_subdirectory(math)
# 头文件
include_directories(include)
# 生成可执行文件
add_executable(my_src main.cpp)