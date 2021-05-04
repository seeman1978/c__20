//
// Created by wq on 2021/5/4.
//
#include <c++/v1/memory>
#include <c++/v1/iostream>

int main(){
    std::unique_ptr<int> p {new int{9} };
    auto lambda1 = [ptr = std::move(p)]{std::cout << *ptr << '\n';};
    lambda1();
}