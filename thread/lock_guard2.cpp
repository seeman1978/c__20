//
// Created by zhaoyue on 2020/11/15.
//

#include <mutex>
#include <iostream>

int main(){
    std::mutex m1, m2;
    {
        std::lock(m1,m2);
        std::lock_guard<std::mutex> lg1(m1, std::adopt_lock);   // std::adopt_lock parameter used to select non-locking version of the constructor
        std::lock_guard<std::mutex> lg2(m2, std::adopt_lock);
        std::cout << "hello ";
    }//m1 ,m2,自动调用unlock，lock和lock_guard的adopt_lock配合使用
    {
        std::lock(m1,m2);
        std::cout << "world ";
        m1.unlock();
        m2.unlock();
    }
    {//这种方法容易造成死锁，不要使用
        std::lock_guard<std::mutex> lg1(m1);   // std::adopt_lock parameter used to select non-locking version of the constructor
        std::lock_guard<std::mutex> lg2(m2);
        std::cout << "hello ";
    }
}