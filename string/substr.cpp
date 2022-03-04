#include <string>
#include <iostream>

/**
* @file
* @brief
* @details
* @author		qiangwang
* @date		    2022/3/4
* @par Copyright(c): 	2022 mega. All rights reserved.
*/

int main(){
    std::string str{"Hello World"};
    str = str.substr(str.find(' '), str.length());
    std::cout << str << '\n';
}