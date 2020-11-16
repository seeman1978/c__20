//
// Created by zhaoyue on 2020/11/15.
//

//
// Created by zhaoyue on 2020/11/11.
//

#include <mutex>
#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

struct X{
    int i=0;
    explicit X(int j):i{j}{

    }
};

X* pX= nullptr;

X* getInstance(){
    static std::atomic<bool> x_init{false};
    static std::once_flag instance_created;
    if (!x_init){
        std::cout << "begin to call once \n";
        std::call_once(instance_created, [&](){ pX = new X(9); });
        std::cout << "end to call once \n";
        x_init = true;
    }
    return pX;
}

void test(){
    X* pAX = getInstance();
    std::cout << " X address is " << pAX << " . X is " << pAX->i << " .\n";
}

int main(){
    std::vector<std::thread> vThread;
    for (int i = 0; i < 10; ++i) {
        vThread.emplace_back(std::thread(test));
    }

    for (auto & v: vThread){
        v.join();
    }
}