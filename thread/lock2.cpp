//
// Created by zhaoyue on 2020/11/15.
//

#include <mutex>
#include <iostream>

int main(){
    std::mutex m1, m2;
    {
        std::lock(m1, m2);
        std::cout << "hello" << '\n';
        m1.unlock();
        m2.unlock();
    }

    {
        std::lock(m1, m2);
        std::cout << "world" << '\n';
        m1.unlock();
        m2.unlock();
    }
}