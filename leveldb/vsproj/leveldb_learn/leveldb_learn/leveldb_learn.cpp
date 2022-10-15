// leveldb_learn.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
    uint32_t hash = 2;
    uint32_t length = 3;
    std::cout << (hash & length) << std::endl;
}
