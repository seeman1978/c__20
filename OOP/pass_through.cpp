//
// Created by wq on 2021/6/13.
//
#include <string>
#include <iostream>
//在C++11中，透传被扩展到构造函数上。子类可以通过使用using声明来继承基类的构造函数

struct Base{
public:
    explicit Base(const std::string& str){
        m_str = str;
    }
    Base()=default;
    void f(double d){
        std::cout << "Base:" << d << '\n';
    }
    void f2(){
        std::cout << "Base:" << m_str << '\n';
    }

protected:
    std::string m_str;
};

struct Derived : Base{
public:
    using Base::Base;   //把基类中的构造函数悉数继承到派生类B中。不过继承构造函数只会初始化基类中成员变量，对于派生类中的成员变量则无能为力。可以通过成员变量初始化来解决这个问题。
    using Base::f;

    void f(int i){
        std::cout << "Derived:" << i << '\n';
    }
};

int main(){
    Base b;
    b.f(4.5f);
    Derived d{"Hello"};
    d.f(5.5f);
    d.f(5);
    d.f2();
    //Derived d2 = std::string{"World"};
}