// C++数据类型长度
// Created by 王强 on 2020/8/25.
//
#include <iostream>

class CA
{};

class CB
{
    int m_i;
};

int main()
{
    printf("char length:%d\n", sizeof(char));
    printf("int length:%d\n", sizeof(int));
    printf("double length:%d\n", sizeof(double));
    CA a;
    printf("Class A length:%d\n", sizeof(CA));

    CB b;
    printf("Class B length:%d\n", sizeof(b));
}