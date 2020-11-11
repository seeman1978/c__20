//
// Created by zhaoyue on 2020/11/11.
//

#include <mutex>
#include <iostream>

struct X{
    int i=0;
    explicit X(int j):i{j}{

    }
};

X* pX= nullptr;
std::mutex lx;
std::atomic<bool> x_init{false};

X* getInstance(){
    if (!x_init){
        lx.lock();
        if (!x_init){
            pX = new X(8);
            x_init = true;
        }
        lx.unlock();
    }
    return pX;
}

int main(){
    X* pAX = getInstance();
    std::cout << "X is " << pAX->i;
}