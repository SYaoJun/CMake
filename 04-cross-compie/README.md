# 第四章：交叉编译

## 编译宏
- 在cmake时通过-DVIP=ABCDEDF传入对应的值
```
target_compile_definitions(main
    INTERFACE
    VIP="${VIP}"
)
```
## 编译参数
```
target_compile_features()
```