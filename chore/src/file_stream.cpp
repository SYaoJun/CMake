
#include <iostream>
#include <fstream>
#include <string>

int main()
{

    std::fstream my_file_;// 实例化一个文件对象
    std::string data;
    my_file_.open("firstFile.txt", std::ios_base::in | std::ios_base::out | std::ios::app); // 打开文件firstFile.txt，可选择三种模式
    if (my_file_.is_open())                                                         // 检测open()是否成功
    {

        my_file_.write(data.data(), data.size());
        my_file_<<"Writing in file";
        my_file_.close(); // 关闭文件流以保存其内容，这一步不能忘
    }
}