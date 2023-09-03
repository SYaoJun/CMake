# 第六章：编译优化
## Ninja Generator 生成器
```c
cmake -B build -G Ninja
```
## CCache 缓存
```
find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
  message(STATUS "Set up ccache ...")
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif()
```
## 预编译头
- Precompiled headers 
- 预编译头文件，可以大大将少 C++ 头文件的重复编译时间，你可以将一些第三方库，比如spdlog/spdlog.h以及项目中很少变动的 C++ 头文件加到预编译中
- 注意：生成的中间文件，会非常大，占用比较大的磁盘空间
```
target_precompile_headers(<my_target> PRIVATE my_pch.h)
```
## 性能优化
- 将debug模式改为release
