//
// Created by wq on 2021/5/4.
//

#include <iostream>

int main(){
    []{std::cout << "hello world" << '\n';}();  //返回类型void

    double y = 2.5;
    auto lambda1 = [=](int x){return x+y;}; //返回类型是double
    std::cout << lambda1(3) << '\n';

    bool bResult = false;
    std::cout << [bResult]{if (bResult) return 1; else return 2;}() << '\n';    //返回类型是int
    //error: return type 'double' must match previous return type 'int' when lambda expression has unspecified explicit return type
    //std::cout << [bResult]{if (bResult) return 1; else return 2.8;}() << '\n';
    std::cout << [bResult]()->double {if (bResult) return 1; else return 2.8;}() << '\n';
    //warning: implicit conversion from 'double' to 'int' changes value from 2.8 to 2
    std::cout << [bResult]()->int {if (bResult) return 1; else return 2.8;}() << '\n';
}