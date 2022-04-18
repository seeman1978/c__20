#include <string>
#include <iostream>

/**
* @file
* @brief
* @details
* @author		qiangwang
* @date		    2022/4/6
* @par Copyright(c): 	2022 mega. All rights reserved.
*/

int main(){
    std::string str{"123abc"};
    std::string str2{'\xe4','\xbd','\xa0','\xe5','\xa5','\xbd'};
    std::cout << str2 << std::endl;
    char bb[7] = {'\xe4', '\xbd', '\xa0', '\xe5', '\xa5', '\xbd', '\x00'};
    std::string str3;
    str3.assign(std::begin(bb), std::end(bb)-1);
    std::cout << str3 << std::endl;
}