#include <iostream>

//
// Created by wq on 2021/5/4.
//
int main(){
    auto y = [] (int first, int second)
    {
        return first + second;
    };
    std::cout << y(5, 7) << '\n';

    auto glambda = [](auto a, auto b) { auto c = a + b; auto d = c*c; return d; };
    double b = glambda(3, 3.14); // ok
    std::cout << b << std::endl;

    auto p = [](auto v1, auto v2, auto v3) { std::cout << v1 << ' ' << v2 << ' ' << v3 << '\n'; };
    p(1, 'a', 3.14); // 输出 1 a 3.14

    // 泛型 lambda，operator() 是有两个形参的模板
    auto blambda = []<class T>(T a, auto b) ->bool { return a < b; };
    std::cout << std::boolalpha << blambda(2, 2.9) << '\n';
    auto clambda = []<class T>(T a, T b) ->bool { return a < b; };
    //std::cout << std::boolalpha << clambda(2, 2.9) << '\n';   //error
    std::cout << std::boolalpha << clambda(2, 3) << '\n';
}
