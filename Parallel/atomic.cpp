//
// Created by 王强 on 2020/11/10.
//

#include <iostream>
#include <atomic>
#include <thread>
#include <future>

long data;
std::atomic<bool> readyFlag{false};

void provider(){
    std::cout << "Please input a character: " << '\n';
    std::cin.get();
    data = 42;

    readyFlag.store(true);
}

void consumer(){
    while (!readyFlag.load()){
        std::cout.put('.').flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::cout << "\nvalue: " << data << '\n';
}

int main(){
    auto p = std::async(std::launch::async, provider);
    auto c = std::async(std::launch::async, consumer);
}