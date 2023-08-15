# C++ Project

整理了一些常用开源库使用 CMake 管理的 Demo 代码

## 编译

```
# build是编译时创建的目录
cd leveldb
cmake -B build
cmake --build build

```

## 安装

```
sudo cmake --install build
```

## 添加库文件

```
include_directories(/usr/local/include)
find_library(LIBS  leveldb /usr/local/lib)
add_executable(leveldb_test leveldb_test.cpp)
target_link_libraries(leveldb_test ${LIBS})
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
