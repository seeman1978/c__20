//
// Created by 王强 on 2020/11/16.
//
#include <iostream>
#include <string>

int main(){
    std::cout << std::boolalpha;
    std::cout << "max(short):" << std::numeric_limits<short>::max() << '\n';
    std::cout << "max(int):" << std::numeric_limits<int>::max() << '\n';
    std::cout << "max(long):" << std::numeric_limits<long>::max() << '\n';

    std::cout << "max(float):" << std::numeric_limits<float>::max() << '\n';
    std::cout << "max(double):" << std::numeric_limits<double>::max() << '\n';
    std::cout << "max(long double):" << std::numeric_limits<long double>::max() << '\n';

    std::cout << "is_signed(char):" << std::numeric_limits<char>::is_signed << '\n';
    //是否有特例化的版本
    std::cout << "is_specialized(string):" << std::numeric_limits<std::string>::is_specialized << '\n';

}