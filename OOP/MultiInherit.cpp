//
// Created by 王强 on 2020/12/2.
//
#include <iostream>
struct A{
    virtual void f(){
        std::cout << "A";
    }
};

struct B{
    virtual void f(){
        std::cout << "B";
    }
};

struct C : public A, B{
    virtual void f(){
        std::cout << "C";
    }
};

int main(){
    {
        C c;
        //c.f();    // 二义性
    }
    std::unique_ptr<A> pA = std::make_unique<C>();
    pA->f();
}