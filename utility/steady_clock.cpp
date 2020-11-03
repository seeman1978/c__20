//
// Created by wq on 2020/10/31.
//

#include <chrono>
#include <iostream>

void f(){
    for (int i = 0; i < 1000000; ++i) {

    }
}
//This clock is not related to wall clock time (for example, it can be time since last reboot)
int main(){
    using namespace std::chrono;

    steady_clock::time_point t1 = steady_clock::now();
    f();
    steady_clock::time_point t2 = steady_clock::now();
    steady_clock::duration d = t2 - t1;
    std::cout << "something took " << duration_cast<milliseconds>(d).count() << "ms" << std::endl;
}