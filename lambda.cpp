//
// Created by 王强 on 2020/2/24.
//

#include <iostream>

int main()
{
    {
        auto glambda = [](auto a, auto b) { auto c = a + b; auto d = c*c; return d; };
        double b = glambda(3, 3.14); // ok
        std::cout << b << std::endl;
    }
    {// c++ 20 feature
        auto glambda = []<typename T>(const T a, const T b) { T c = a + b; T d = c*c; return d; };
        double b = glambda(3, 5); // ok, 3.14 will be failed here.
        std::cout << b << std::endl;
    }
    {// c++ 20 feature
        auto glambda = []<typename T>(const T a, const T b) { T c = a + b; T d = c*c; return d; };
        double b = glambda(3.0, 3.14); // ok
        std::cout << b << std::endl;
    }
}