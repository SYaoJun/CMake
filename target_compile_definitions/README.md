# target_compile_definitions
用于给目标添加编译参数，比如定义宏。
不管是使用private还是interface还是public对外部的调用者都没影响，一般建议使用private。
```cmake
target_compile_definitions(mylib PRIVATE USE_A)
```
