# 对象库
只要创建了对象库，可以在任何地方使用。
这两种方式都是可以的
```
target_link_libraries(main PRIVATE $<TARGET_OBJECTS:internal_add>)
target_link_libraries(main PRIVATE internal_add)
```