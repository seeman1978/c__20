//
// Created by 王强 on 2020/9/7.
//
#include <iostream>
struct readout{
    char hour;
    int value;
    char seq;
};

struct small_readout{
    int value;
    char hour;
    char seq;
};

int main()
{
    int i = sizeof(readout);
    //对象对齐，struct readout的长度是12
    std::cout << "struct readout size is " << i << std::endl;

    int j = sizeof(small_readout);
    //对象对齐，struct readout的长度是12
    std::cout << "struct small readout size is " << j;
}