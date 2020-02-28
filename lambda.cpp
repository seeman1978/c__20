//
// Created by 王强 on 2020/2/24.
//

#include <iostream>

int main()
{
    auto glambda = [](auto a, auto b) { auto c = a + b; auto d = c*c; return d; };
    double b = glambda(3, 3.14); // ok
    std::cout << b;
}