//
// Created by 王强 on 2021/1/21.
//

#include <chrono>
#include <thread>
#include <future>
#include <iostream>

int quickComputation(){
    std::this_thread::sleep_for(std::chrono::seconds(3));
    return 3;
}

int accurateComputation(){
    std::this_thread::sleep_for(std::chrono::seconds(6));
    return 6;
}

int bestResultInTime(std::future<int> &f){
    auto tp = std::chrono::system_clock::now() + std::chrono::seconds(5);
    f = std::async(std::launch::async, accurateComputation);

    int guess = quickComputation();

    std::future_status s = f.wait_until(tp);
    if (s == std::future_status::ready){
        return f.get();
    }
    else{
        return guess;
    }
}

int main(){
    //注意futuref不能是声明于bestResultInTime（）内的local对象，那样的话若时间太短以至于无法完成accurateComputation（），
    // future析构函数会停滞（block）直到异步操作结束。
    std::future<int> f;

    std::cout << bestResultInTime(f);
}