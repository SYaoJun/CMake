# C++ Project
整理了一些CMake管理的C++ demo文件
## Git
```c
# 显示分支
git branch -a
# 添加源文件
git add src/test.cpp
# 提交
git commit -m "cooment"
# 回到某个版本
git reset --hard xxx  
# 关联仓库项目
git remote add repo_name git@github.com:SYaoJun/Shiro-and-JWT.git
# 强制推送当前分支到远端
git push origin HEAD 
# 显示标签
git tag
# 切换分支
git checkout -b v1.23 v1.23
```

## CMake
```cmake
add_library()
target_link_library()
target_include_directories()
target_sources()
include_directories()
find_package()
add_subdirectory()
find_program()
set_property()
add_compile_options()
option()
string()
message()
add_custom_target()

```

