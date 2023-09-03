# 第三章：引入外部项目

## 1\. submodule

```
git submodule add git@gitee.com:roberchen/spdlog.git
git submodule init
git submodule update
```

## 2\. external_project

- 在编译时下载项目并引入
- XXX.cmake
- target_link_libraries
- target_include_directories

## 3\. FetchContent

## 参考文档

[CMakeTutorial](https://github.com/BrightXiaoHan/CMakeTutorial/blob/master/ImportExternalProject/README.md)
