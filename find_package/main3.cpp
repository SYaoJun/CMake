#include <iostream>

void memoryLeakExample() {
    int* leak = new int[10];  // 分配了10个int的数组，但没有释放
    leak[0] = 1;              // 使用分配的内存
    // 未调用 delete[] leak;
}

int main() {
    memoryLeakExample();
    std::cout << "Program finished." << std::endl;
    return 0;
}