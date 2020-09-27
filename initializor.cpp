//
// Created by 王强 on 2020/9/24.
//
#include <string>
class A{
public:
    std::string m_str;
    int m_i;
    double m_d;
    std::string m_str2;
};


#include <iostream>

int main(){
    int a0 = 0;
    int a1{};

    int *p1 = new int;
    int *p2 = new int {};

    std::cout << "a0 is " << a0 << std::endl
        << "a1 is " << a1 << std::endl
        << "p1 is " << *p1 << std::endl
        << "p2 is " << *p2 << std::endl;
    delete p1;
    delete p2;

    A a{"hello", 7};    //按照顺序初始化

}