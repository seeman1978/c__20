//
// Created by zhaoyue on 2020/11/5.
//

#include <iostream>

void func(int i){
    std::cout << i << std::endl;
}

typedef decltype(func) FuncType;    // 声明一个函数类型
void test(FuncType pFunc){  //编译器会自动将函数类型自动转换成函数指针类型
    pFunc(3);
}

int main(){
    {
        typedef decltype(func)* FuncPointer;    // 声明一个函数指针类型
        FuncPointer pFunc = func;   //定义一个函数指针
        pFunc(1);   //调用函数指针
    }
    {
        typedef decltype(func) FuncType;    // 声明一个函数类型
        FuncType* pFunc = func;   //定义一个函数指针
        pFunc(2);   //调用函数指针
    }
    {
        FuncType* pFunc = func;   //定义一个函数指针
        test(pFunc);
    }
    {
        using FuncPointer = decltype(func); // 声明一个函数类型
        FuncPointer* pFunc = func;  //定义一个函数指针
        pFunc(4);
    }
    {
        using FuncPointer = decltype(func) *;   // 声明一个函数指针类型
        FuncPointer pFunc = func;   //定义一个函数指针
        pFunc(5);
    }
}