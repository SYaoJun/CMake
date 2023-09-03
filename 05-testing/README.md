# 单元测试
```
include(CTest)
enable_testing()
add_test()
```
## 编译运行
```
ctest --test-dir build
# 或者只测试cs开头的数据
ctest --test-dir build -R "^cs." 
```
## 宏macro
- ${ARGN}是所有传入的可变参数
```cmake
macro(my_add_test TEST_NAME)
    add_executable(${TEST_NAME} ${ARGN}) 
    add_test(NAME cs.${TEST_NAME} COMMAND ${TEST_NAME})
    target_link_libraries(${TEST_NAME} PRIVATE gtest gtest_main)
endmacro()
```

## 函数function
```cmake
function(add_thirdparty)
    cmake_parse_arguments(DORIS_THIRDPARTY
        "NOTADD;LIB64"
        "LIBNAME;WHOLELIBPATH"
        ""
        ${ARGN})
    set(DORIS_THIRDPARTY_NAME ${DORIS_THIRDPARTY_UNPARSED_ARGUMENTS})
    add_library(${DORIS_THIRDPARTY_NAME} STATIC IMPORTED)
endfunction()
```
