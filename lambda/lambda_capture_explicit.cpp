//
// Created by wq on 2021/5/4.
//

#include <c++/v1/string>
#include <c++/v1/iostream>

int main(){
    int i = 9;
    std::string str{"hello"};
    auto lambda1 = [&str, i]{
        str += " world\n";
        std::cout << str;
        std::cout << i;
    };
    lambda1();
}