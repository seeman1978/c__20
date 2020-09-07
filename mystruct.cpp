//
// Created by 王强 on 2020/9/7.
//
#include <iostream>
struct readout{
    char hour;
    int value;
    char seq;
};

int main()
{
    int i = sizeof(readout);
    //对象对齐，struct readout的长度是12
    std::cout << "struct readout size is " << i;
}