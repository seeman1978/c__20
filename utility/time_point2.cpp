//
// Created by zhaoyue on 2020/11/17.
//

#include <string>
#include <chrono>
#include <iostream>

std::string asString(const std::chrono::system_clock::time_point &tp) {
    std::time_t t = std::chrono::system_clock::to_time_t(tp);
    std::string ts = std::ctime(&t);    //会考虑时区
    return ts;
}

int main(){
    std::chrono::system_clock::time_point tp;
    std::cout << "epoch:" << asString(tp);

    tp = std::chrono::system_clock::now();
    std::cout << "now:" << asString(tp);

    tp = std::chrono::system_clock::time_point::min();
    std::cout << "min:" << asString(tp);

    tp = std::chrono::system_clock::time_point::max();
    std::cout << "max:" << asString(tp);
}