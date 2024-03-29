//
// Created by 王强 on 2020/3/4.
//
#include <iostream>

enum class altitude: char
{
    high='h',
    low='l', // C++11 allows the extra comma
};

// altitude may be altitude::high or altitude::low
enum class color : int
{
    red=0,
    yellow=1, // C++11 allows the extra comma
};

//error . in enum class 不可以把另一个枚举变量作为成员变量
//enum class color2 : int{
//    color color1; //error
//    green = 2;
//};

int main(){
    altitude a;
    a = altitude::low;

    color my = color::yellow;

    std::cout << "altitude:" << static_cast<char>(a) << std::endl;

    std::cout << "color:" << static_cast<int>(my) << std::endl;
}