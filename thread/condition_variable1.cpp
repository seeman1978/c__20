//
// Created by 王强 on 2021/1/23.
// 例子来源C++标准库第2版

#include <mutex>
#include <iostream>
#include <future>

bool readyFlag = false;
std::mutex readyMutex;
std::condition_variable readyCondVar;

void thread1(){
    std::cout << "<return>" << '\n';
    std::cin.get();
    {
        std::lock_guard<std::mutex> lg(readyMutex);
        readyFlag = true;
    }
    readyCondVar.notify_one();
}

void thread2(){
    {
        std::unique_lock<std::mutex> ul(readyMutex);
        readyCondVar.wait(ul, []{return readyFlag;});
    }
    std::cout << "done" << '\n';
}

int main(){
    auto f1 = std::async(std::launch::async, thread1);
    auto f2 = std::async(std::launch::async, thread2);
    f1.wait();
    f2.wait();
}