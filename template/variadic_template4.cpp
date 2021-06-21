//
// Created by wq on 2021/6/22.
//
#include <iostream>
struct A{
    A()=default;
    A(const A& a){
        std::cout << "Copy Constructed " << __func__ << '\n';
    }
};

struct B{
    B()=default;
    B(const B& b){
        std::cout << "Copy Constructed " << __func__ << '\n';
    }

    B(B&& b){
        std::cout << "Move Constructed " << __func__ << '\n';
    }
};

// 变长模版的定义
template <typename... T>
struct MultiTypes;

template <typename T1, typename... T>
struct MultiTypes<T1, T...> : public MultiTypes<T...>{
    T1 t1;
    MultiTypes<T1, T...>(T1 a, T... b):t1{a}, MultiTypes<T...>(b...){
        std::cout << "MultiTypes<T1, T...>(T1 a, T... b)" << '\n';
    }
};

template<> struct MultiTypes<>{
    MultiTypes<>(){
        std::cout << "MultiTypes<>()" << '\n';
    }
};

// 完美转发变长模版
template<template<typename...> class VariadicType, typename... Args>
VariadicType<Args...> Build(Args&&... args){
    return VariadicType<Args...>(std::forward<Args>(args)...);
}

int main(){
     A a;
     B b;
     Build<MultiTypes>(a, b);
}