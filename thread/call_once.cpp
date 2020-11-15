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

X* getInstance(){
    static X *the_instance = nullptr;
    static std::once_flag instance_created;
    if (the_instance != nullptr){
        return the_instance;
    } else{
        std::call_once(
                instance_created,
                [&](){ the_instance = new X(9); }
        );
        return the_instance;
    }
}

void test(){
    X* pAX = getInstance();
    std::cout << " X address is " << pAX << ". X is " << pAX->i << " .\n";
}

int main(){
    X* pAX = getInstance();
    std::cout << " X is " << pAX->i << " .\n";

    X* pBX = getInstance();
    std::cout << " X is " << pBX->i << " .\n";

    std::vector<std::thread> vThread;
    for (int i = 0; i < 10; ++i) {
        vThread.emplace_back(std::thread(test));
    }

    for (auto & v: vThread){
        v.join();
    }
}