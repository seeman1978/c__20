//
// Created by wq on 2021/5/4.
//

#include <c++/v1/iostream>

int main(){
    int y = 32;
    auto answer = [y]() constexpr {
        int x = 10;
        return y+x;
    };
    std::cout << answer() << '\n';
}