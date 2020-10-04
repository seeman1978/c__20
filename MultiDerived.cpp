//
// Created by zhaoyue on 2020/10/4.
//

#include <iostream>

class A{
public:
    void f(){
        std::cout << "f() in class A" << std::endl;
    }
};

class B{
public:
    void f(){
        std::cout << "f() in class B" << std::endl;
    }
};

class C:public A, public B{

};

int main(){
    C c;
    //c.f();    //member 'f' found in multiple base classes of different types, 具有二义性
    c.B::f();   //类限定符
}