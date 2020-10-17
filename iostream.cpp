//
// Created by wq on 2020/10/17.
//
#include <iostream>
#include <sstream>

int main(){
    std::ostringstream oss{"Label:", std::ios::ate};    //在部追加
    std::cout << oss.str() << std::endl;

    oss << "val";
    std::cout << oss.str() << std::endl;

    std::ostringstream oss2{"Label2:"}; //头部写
    std::cout << oss2.str() << std::endl;
    oss2 << "val2";
    std::cout << oss2.str() << std::endl;   //输出val2l2:

    std:stringstream oss3{"", std::ios::ate};
    oss3 << 3 << " hello " << "world";
    std::cout << oss3.str() << std::endl;
}