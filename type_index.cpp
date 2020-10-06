//
// Created by zhaoyue on 2020/10/6.
//
#include <typeindex>
#include <unordered_map>
#include <string>
#include <iostream>

class A{
public:
    virtual ~A(){}
};

class B: public A{

};

class C: public A{

};

int main(){
    std::unordered_map<std::type_index, std::string> type_names;
    type_names[std::type_index(typeid(int))] = "int";
    type_names[std::type_index(typeid(double))] = "double";
    type_names[std::type_index(typeid(A))] = "A";
    type_names[std::type_index(typeid(B))] = "B";
    type_names[std::type_index(typeid(C))] = "C";

    int i = 0;
    double d = 0.0;
    A a;
    std::unique_ptr<A> pB{new B};
    std::unique_ptr<A> pC{new C};

    std::cout << "i is " << type_names[std::type_index(typeid(i))] << std::endl;
    std::cout << "d is " << type_names[std::type_index(typeid(d))] << std::endl;
    std::cout << "a is " << type_names[std::type_index(typeid(a))] << std::endl;
    std::cout << "b is " << type_names[std::type_index(typeid(*pB))] << std::endl;
    std::cout << "c is " << type_names[std::type_index(typeid(*pC))] << std::endl;
}