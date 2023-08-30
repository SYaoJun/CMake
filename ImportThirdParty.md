# 第三方依赖管理
- 支持 CMake 的项目，基本上都会提供一个类似于 xxx-config.cmake 或者 xxxConfig.cmake 的文件，它们的作用就是提供查找与引入到当前项目以供使用。
## find_path和find_library
- 需要安装到本地。
## fetchContent
- 直接从源码仓库中获取代码，源码编译。
## find_package
- 只有部分cmake支持的库可以找到，或者设置了FindXX.cmake文件
## ExternalProject