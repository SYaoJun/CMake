#include <iostream>
#include <fstream>
#include <string>


int main() {
    const std::string filename("hello.txt");
    std::string buffer("xyz");

    std::fstream my_file;
    my_file.open(filename, std::ios::in | std::ios::app);

    my_file.seekg(0, std::ios::beg); // 把get流指针移动到开头
    // std::cout<<"size = "<<size<<std::endl;
    my_file.write(buffer.data(), buffer.size()); // 往文件写入3个字节
    int size = my_file.tellg();// get流指针的位置
    my_file.flush();
    my_file.sync(); // C++中的flush和sync没有区别
    my_file.close();
    std::cout << "the complete file is in a buffer, size = " << size
              << std::endl;
    return 0;
}
