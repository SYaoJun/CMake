# C++ Project

-   整理了一些使用`CMake`管理的样例代码，所有使用到的库都需要手动安装到本地，比如`leveldb`和`duckdb`。
## 构建生成器文件时可选参数
- 如果需要学习第三方库，在编译安装时使用debug模式。
```
-DCMAKE_BUILD_TYPE=Debug
-DCMAKE_BUILD_TYPE=Release
-DCMAKE_INSTALL_PREFIX=/your/install/path
-DCMAKE_CXX_STANDARD=11
```
## 可用样例列表
- google_test
-   leveldb
-   duckdb
-   arrow
-   crc
-   catch2
-   abseil

## 依赖说明
- 第三方库需要先安装，建议安装到指定目录下，直接删除就相当于卸载，若安装时没指定安装目录，默认安装如下：
-   所有头文件都放在`/usr/local/include`目录下
-   所有静态库都放在`/usr/local/lib`目录下

## 编译

```
# build是编译时创建的目录
cd leveldb
cmake -B build
cmake --build build

```
## 指定安装路径
```
cmake -DCMAKE_INSTALL_PREFIX=/your/install/path ..
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
## fetch_content
在Linux环境可以正常运行，在Mac环境存在链接错误