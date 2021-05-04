//
// Created by wq on 2021/5/4.
//

#include <c++/v1/iostream>

int main(){
    int j = 0;
    [=]()mutable {j = 8;std::cout << j<<'\n';}();
}