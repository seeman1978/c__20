//
// Created by zhaoyue on 2020/11/15.
//

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
private:
    X()=default;
    explicit X(int j):i{j}{

    }

public:
    int i=0;
    static X* getInstance(){
        static std::atomic<bool> x_init{false};
        static std::once_flag o_f;
        static X* pAX{nullptr};
        if (!x_init){
            std::cout << "begin to call once \n";

            std::call_once(o_f, [&](){ pAX = new X(9); });
            std::cout << "end to call once \n";
            x_init = true;
        }
        return pAX;
    }
};


void test(){
    X* pAX = X::getInstance();
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