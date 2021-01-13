//
// Created by 王强 on 2021/1/13.
//

#include <string>
#include <sstream>
#include <iostream>

int main(){// 从浮点数中分离出整数部分和小数部分
    int x=0;
    float f=0;
    std::string s = "3.7";
    std::istringstream is(s);
    is >> x >> f;
    std::cout << x << '\n';
    std::cout << f << '\n';
}