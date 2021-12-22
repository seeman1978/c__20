//
// Created by wq on 2021/11/30.
//

#include <iostream>
#include <thread>
#include <unistd.h>

std::condition_variable g_cv;
std::mutex g_mutex;

int main(){
    std::cout << "a\n";
    std::thread t1([](){
        std::cout << "b\n";
        std::unique_lock<std::mutex> lock{g_mutex};
        g_cv.wait(lock);
        std::cout << "d\n";
    });

    sleep(1);
    std::cout << "c\n";
    g_cv.notify_one();

    t1.join();
}