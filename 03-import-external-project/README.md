# 第三章：引入外部项目

## 1\. submodule
- 把一个已有的仓库作为子模块添加到主项目中，如果子模块也有依赖，需要递归地拉取代码到本地。
- 直接源码编译。
```
git submodule add git@gitee.com:roberchen/spdlog.git
git submodule init
git submodule update --init --recursive
```

## 2\. external_project
- 在编译时下载项目并引入到主项目中
```
include(ExternalProject)
ExternalProject_Add(SPDLOG
        PREFIX            ${SPDLOG_ROOT}
        GIT_REPOSITORY    ${SPDLOG_GIT_URL}
        GIT_TAG           ${SPDLOG_GIT_TAG}
        CONFIGURE_COMMAND ${SPDLOG_CONFIGURE}
        BUILD_COMMAND     ${SPDLOG_MAKE}
        INSTALL_COMMAND   ${SPDLOG_INSTALL}
)
```

## 3\. FetchContent
```
 include(FetchContent)
 FetchContent_Declare(
         googletest
         GIT_REPOSITORY https://github.com/google/googletest.git
         GIT_TAG v1.14.0
 )
 FetchContent_MakeAvailable(googletest)

add_executable(gtest_test gtest_test.cpp)
target_link_libraries(gtest_test gtest_main)
```
## 4. find_package
- 查找系统中安装好的三方包
```
find_package(GTest REQUIRED)
target_link_libraries(gtest_test GTest::gtest GTest::gtest_main)
```

## 5. find_library
- 给定路径查找
```
find_library(DB_LIBS
        NAMES duckdb
        PATHS /Users/yaojun/MyInstall/duckdb_install/usr/local/lib
        REQUIRED)
include_directories(/Users/yaojun/MyInstall/duckdb_install/usr/local/include)
target_link_libraries(duckdb_test ${DB_LIBS})
```
## 参考文档

[CMakeTutorial](https://github.com/BrightXiaoHan/CMakeTutorial/blob/master/ImportExternalProject/README.md)
