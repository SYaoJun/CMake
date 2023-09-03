# 第二章：生成与使用库文件
- 使用`add_library`命令可以生成：
    1. 静态库
    2. 动态库
    3. 对象库
    4. ...

## 目录结构
```
├── CMakeLists.txt
├── hello
│   ├── CMakeLists.txt
│   ├── hello.cpp
│   └── hello.h
├── main
│   ├── CMakeLists.txt
│   └── main.cpp
└── world
    ├── CMakeLists.txt
    ├── world.cpp
    └── world.h
```
## 静态库
- STATIC必须要大写
```
add_library(world STATIC world.h world.cpp)
```
## 动态库
- SHARED必须要大写
```
add_library(world SHARED world.h world.cpp)
```

## 依赖关系
- 为了保证在执行main之前，先执行hello和world。
```
add_dependencies(main hello world)
```


