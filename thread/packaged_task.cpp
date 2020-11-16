//
// Created by zhaoyue on 2020/11/16.
//
#include <stdexcept>
#include <future>
#include <iostream>

int ff(int i){
    if (i){
        return i;
    }
    else{
        throw std::runtime_error("ff(0)");
    }
}

int main(){
    std::packaged_task<int(int)> pt1{ff};
    std::packaged_task<int(int)> pt2{ff};

    pt1(1);
    pt2(0);

    auto v1 = pt1.get_future();
    auto v2 = pt2.get_future();

    try {
        std::cout << v1.get() << '\n';
        std::cout << v2.get() << '\n';
    }
    catch (std::exception& e) {
        std::cout << "exception:" << e.what() << '\n';
    }
}

