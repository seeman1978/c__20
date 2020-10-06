//
// Created by zhaoyue on 2020/9/4.
//
#include <iostream>
static int i = 9;

class A{
public:
    static double m_d;  //被使用，必须初始化
    static int m_i;     //未使用，可以不初始化
};

double A::m_d = 0.0;

int main()
{
    int j  = i * 2;
    printf("%d\n", j);

    std::cout << A::m_d << std::endl;
}
