//
// Created by 王强 on 2020/10/4.
//
#include <iostream>

class A{

};

class B{

};

class Base{

};

class Derived: public Base{

};

class Derived2: public Base{

};

int main(){
    int *pI = new int{19};

    A* pA = new A;

    //pA = dynamic_cast<A*>(pI);    //无法编译，编译器知道类型不匹配

    B* pB = new B;

    //pA = dynamic_cast<A*>(pB);  //无法编译，编译器知道类型不匹配

    Derived* pD = new Derived;
    Base* pBase = dynamic_cast<Base*>(pD);

    //pD = dynamic_cast<Derived*>(pBase);   //无法编译，编译器知道类型不匹配

    std::cout << typeid(*pBase).name() << std::endl;

    Derived2* pD2 = new Derived2;
    //pD2 = dynamic_cast<Derived2*>(pBase); //无法编译，编译器知道类型不匹配



}