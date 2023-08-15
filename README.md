# C++ Project

整理了一些 CMake 管理的 C++ demo 文件

## 编译安装

```
# build是编译时创建的目录
cd leveldb
cmake -B build
cmake --build build
sudo cmake --install build
```

## 常用命令

```cmake
add_library()
target_link_library()
target_include_directories()
target_sources()
include_directories()
find_package()
add_subdirectory()
find_program()
set_property()
add_compile_options()
option()
string()
message()
add_custom_target()

```
