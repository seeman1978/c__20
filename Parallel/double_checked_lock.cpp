//
// Created by zhaoyue on 2020/11/11.
//

#include <mutex>
#include <iostream>
#include <atomic>

struct X{
    int i=0;
    explicit X(int j):i{j}{

    }
};

X* pX= nullptr;
std::mutex lx;
std::atomic<bool> x_init{false};

//new操作会被编译器分为三步：1、分配内存空间；2、调用构造函数，初始化；3将分配的地址赋值给指针。
//这三个步骤，在不同的编译器中会不相同，有个编译器会颠倒步骤2和3。如果步骤2和3颠倒，则下面这段
//代码在有时将产生不可预期的行为。
/*
X* getInstance(){
    if (pX == nullptr){
        std::lock_guard<std::mutex> lg(lx);
        if (px == nullptr){
            pX = new X(8);
        }
    }
    return pX;
}*/

X* getInstance(){
    if (!x_init){
        std::lock_guard<std::mutex> lg(lx);
        if (!x_init){
            pX = new X(8);
            x_init = true;
        }
    }
    return pX;
}

int main(){
    X* pAX = getInstance();
    std::cout << "X is " << pAX->i;
}