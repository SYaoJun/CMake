# C和C++混合使用
## 目标：C代码中调用C++的动态库
```bash
├── CMakeLists.txt
├── b.cpp
├── b.h
└── main.c
```
## C代码中引用C++的动态库
必须保证C++的动态库的头文件中，添加过extern关键字。
```c
#ifdef __cplusplus
extern "C" {
#endif

int add(int a, int b);
#ifdef __cplusplus
}
#endif
```
- C代码中不能使用C++提供的std::string和std::vector，无法编译通过。
- C++提供给C的接口也必须改造为C的接口，否则C代码无法调用。