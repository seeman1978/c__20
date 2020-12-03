//
// Created by 王强 on 2020/12/3.
//
#include <string>
#include <iostream>
struct A{
    A()=default;
    A(int i, std::string str):m_i{i}, m_str{std::move(str)}{

    }

protected:
    int m_i=0;
    std::string m_str;
};

struct B : public A{
    void func(){
        std::cout << m_str << " " << m_i;
    }
};

struct C : public A{
    //对于基类的每个构造函数，编译器都在派生类中生成一个形参列表完全相同的构造函数。
    using A::A; //继承A的构造函数.
    void func(){
        std::cout << m_str << " " << m_i;
    }
};

int main(){
    B b;
    b.func();

    //B b2{10, "hello"};

    C c{10, "hello"};
    c.func();
}