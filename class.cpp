//
// Created by zhaoyue on 2020/9/23.
//
#include <iostream>

class A{
public:
    A()=default;


    A(int i):m_i(i){
        std::cout << "i is " << m_i << std::endl;
    }

    explicit A(double d):m_d(d){
        std::cout << "d is " << m_d << std::endl;
    }

    ~A()=delete;
private:
    int m_i;
    double m_d;
};

int main(){
    //A a = 9;        //调用隐式构造函数
    //A d {7.8};
    //A a2 = a ;

    A* pA {new A};
    //delete pA;
}