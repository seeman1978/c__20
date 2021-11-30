//
// Created by qiangwang on 2021/8/13.
//

#include <thread>
#include <iostream>

void func(){
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "func\n";
}

void foo(){
    std::thread t{func};
    t.detach(); //if don't invoke detach, it will throw exception.
}

int main(){
    foo();
    std::this_thread::sleep_for(std::chrono::seconds(6));
    std::cout << "main\n";
}