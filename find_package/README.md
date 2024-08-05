## 知识点
1. find_package
2. gtest
3. coverage
4. asan
5. ctest
## 已验证环境
ubuntu 24.04
## 内存泄露
```c
Program finished.

=================================================================
==2126288==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 40 byte(s) in 1 object(s) allocated from:
    #0 0x76f3bd6fc818 in operator new[](unsigned long) ../../../../src/libsanitizer/asan/asan_new_delete.cpp:98
    #1 0x5ca49bcf55e0 in memoryLeakExample() /home/ubuntu/CMakeTutorial/find_package/main3.cpp:4
    #2 0x5ca49bcf565c in main /home/ubuntu/CMakeTutorial/find_package/main3.cpp:10
    #3 0x76f3bce2a1c9  (/lib/x86_64-linux-gnu/libc.so.6+0x2a1c9) (BuildId: 08134323d00289185684a4cd177d202f39c2a5f3)
    #4 0x76f3bce2a28a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2a28a) (BuildId: 08134323d00289185684a4cd177d202f39c2a5f3)
    #5 0x5ca49bcf54f4 in _start (/home/ubuntu/CMakeTutorial/find_package/build/main3+0x24f4) (BuildId: 466ef14455e6e3825441fa99475e19be574a593d)

SUMMARY: AddressSanitizer: 40 byte(s) leaked in 1 allocation(s).
```