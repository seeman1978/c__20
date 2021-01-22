
//
// Created by 王强 on 2021/1/22.
//
//例子来源C++标准库第2版

#include <mutex>
#include <iostream>
#include <future>


std::mutex printMutex;

void print(const std::string& s){
    std::lock_guard<std::mutex> l(printMutex);
    for (char c: s){
        std::cout.put(c);
    }
    std::cout << std::endl;
}

int main(){
    auto f1 = std::async(std::launch::async, print, "Hello from a first thread");
    auto f2 = std::async(std::launch::async, print, "Hello from a second thread");
    print("Hello from the main thread");
}
