/**
* @file
* @brief
* @details
* @author		qiangwang
* @date		    2022/3/1
* @par Copyright(c): 	2022 mega. All rights reserved.
*/
#include <memory>
#include <iostream>

class A{
public:
    ~A(){
        std::cout << "~A\n";
    }
    int i_{5};
    int* f(){
        return &i_;
    }

    void deleter(int p){
        std::cout << "do something\n";
    }
};

int main(){
    A a;
    std::unique_ptr<int, void(*)(int*)> p{a.f(), [](int* ptr){std::cout << "deleter " << *ptr << "\n"; }};
    std::cout << *p << "\n";
}