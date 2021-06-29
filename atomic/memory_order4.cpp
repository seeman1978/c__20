//
// Created by 86186 on 6/29/2021.
//

#include <atomic>
#include <iostream>
#include <thread>

std::atomic<int> a, b;

void thread1(){
    int t{1};
    a.store(t, std::memory_order_relaxed);  //弱序
    b.store(2, std::memory_order_release);  //本原子操作前，所有的写原子操作必须完成。可以保证a的赋值一定在b之前
}

void thread2(){
    while (b.load(std::memory_order_acquire) != 2){
        //自旋，本原子操作必须完成才能执行之后所有的读原子操作
    }
    std::cout << a.load(std::memory_order_relaxed) << '\n'; //可以保证b在a之前读
}

int main(){
    std::thread t1{thread1}, t2{thread2};
    t1.join();
    t2.join();
}