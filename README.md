# C++ Project

-   整理了一些使用`CMake`管理的样例代码，所有使用到的库都需要手动安装到本地，比如`leveldb`和`duckdb`。

## 可用样例列表

-   leveldb
-   duckdb
-   arrow
-   crc
-   catch2
-   abseil

## 依赖说明

-   所有头文件都放在`/usr/local/include`目录下
-   所有静态库都放在`/usr/local/lib`目录下

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
