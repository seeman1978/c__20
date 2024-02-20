//
// Created by wq on 24-2-20.
//

#include <memory>
#include <iostream>

class A{
public:
    int i{};
};

void f(A* pA){
    if (pA != nullptr){
        pA->i = 100;
    }
}

int main(){
    std::shared_ptr<A> pA = std::make_shared<A>();
    pA->i = 10;
    f(pA.get());
    std::cout << pA->i << std::endl;
}