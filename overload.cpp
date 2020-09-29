//
// Created by 王强 on 2020/9/29.
//

#include <iostream>

class Base{
public:
    void f(int i){
        std::cout << "class Base is " << i << std::endl;
    }
};

class Derived: public Base{
public:
    using Base::f;
    void f(std::string str) {
        std::cout << "class Derived is " << str << std::endl;
    }
};

int main(){
    Derived d;
    d.f("hello");
    d.f(12);

    Base* pBase = new Derived();
    pBase->f(8);

}