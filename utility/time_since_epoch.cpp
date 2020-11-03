//
// Created by wq on 2020/10/31.
//
#include <chrono>
#include <iostream>
int main(){
    using namespace std::chrono;
    const auto p0 = std::chrono::time_point<std::chrono::system_clock>{};
    const auto p1 = system_clock::now();
    const auto p2 = p1 - hours(24);

    std::time_t epoch_time = std::chrono::system_clock::to_time_t(p0);
    std::cout << "epoch: " << std::ctime(&epoch_time);
    std::time_t today_time = std::chrono::system_clock::to_time_t(p1);
    std::cout << "today: " << std::ctime(&today_time);

    std::cout << "hours since epoch: "
            << duration_cast<hours>(p1.time_since_epoch()).count() << " hours.\n";
    std::cout << "yesterday , hours since epoch: "
            << duration_cast<hours>(p2.time_since_epoch()).count() << " hours.\n";

    std::cout << "hours since epoch: "
              << time_point_cast<hours>(p1).time_since_epoch().count()  << " hours.\n";
    std::cout << "yesterday , hours since epoch: "
              << time_point_cast<hours>(p2).time_since_epoch().count() << " hours.\n";
}