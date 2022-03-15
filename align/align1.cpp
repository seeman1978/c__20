#include <iostream>

/**
* @file
* @brief
* @details
* @author		qiangwang
* @date		    2022/3/15
* @par Copyright(c): 	2022 mega. All rights reserved.
*/

struct MyData{
    short Data1;
    short Data2;
    short Data3;
};

struct MixedData
{
    char Data1;
    short Data2;
    int Data3;
    char Data4;
};

struct MixedData2
{
    char Data1;
    char Data4;
    short Data2;
    int Data3;
};

int main(){
    MyData data{};
    std::cout << sizeof data << "\n";
    MixedData mix_data{};
    std::cout << sizeof mix_data << "\n";
    MixedData2 mix_data2{};
    std::cout << sizeof mix_data2 << "\n";
}