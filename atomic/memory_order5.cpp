//
// Created by 86186 on 6/29/2021.
//

#include <atomic>
#include <string>
#include <cassert>
#include <thread>

std::atomic<std::string*> ptr;
std::atomic<int> data;

void producer(){
    auto p = new std::string("Hello");
    data.store(42, std::memory_order_relaxed);
    ptr.store(p, std::memory_order_release);
}

void consumer(){
    std::string* p2;
    while (!(p2 = ptr.load(std::memory_order_consume))){ //不保证ptr.load一定发生在data.load之前
        //空指针，自旋等待
    }
    assert(*p2 == "Hello"); //总是相等
    assert(data.load(std::memory_order_relaxed) == 42); //可能断言失败
}

int main(){
    std::thread t1{producer}, t2{consumer};
    t1.join();
    t2.join();
}