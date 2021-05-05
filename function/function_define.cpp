//
// Created by wq on 2021/5/5.
//

#include <c++/v1/iostream>

int& boom(int i)
{
    int value {i};

    return value;
}

int main(){
    int j = boom(7);
    std::cout << j << '\n';
}