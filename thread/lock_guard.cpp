//
// Created by zhaoyue on 2020/11/15.
//
#include <mutex>
#include <thread>
#include <iostream>

int g_i = 0;
std::mutex g_i_mutex;

void safe_increment(){
    const std::lock_guard<std::mutex> mylock(g_i_mutex);
    ++g_i;
    std::cout << std::this_thread::get_id() << ": " << g_i << '\n';

    // g_i_mutex is automatically released when lock
    // goes out of scope
}

int main(){
    std::cout << "main:" << g_i << '\n';
    std::thread t1(safe_increment);
    std::thread t2(safe_increment);
    t1.join();
    t2.join();
    std::cout << "main: " << g_i << '\n';
}

