# protobuf

## 查看版本
```
protoc --version
```
## 生成业务文件
```
protoc --proto_path=. --cpp_out=. person.proto
```

## 注意
- 使用find_package引入第三方包不需要手动引入头文件，经过测试应该是默认自动引入了。
```
include_directories(${PROTOBUF_INCLUDE_DIRS})
```
## 参考文档
[Protobuf教程](https://zhuanlan.zhihu.com/p/503759822)