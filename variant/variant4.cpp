#include <array>
#include <variant>
#include <string>
#include <iostream>

/**
* @file
* @brief
* @details
* @author		qiangwang
* @date		    2022/2/10
* @par Copyright(c): 	2022 mega. All rights reserved.
*/

int main(){
    std::variant<int, float, std::string> intFloatString;
    std::array<std::variant<int, float, std::string>, 5> arr;
    arr[0] = 11;
    arr[1] = 2.456f;
    arr[2] = "Hello world";
    arr[3] = 4.5f;
    arr[4] = "ni hao";
    for (const auto& a : arr) {
        std::cout << a.index() << '\n';
    }

    for (const auto& a : arr) {
        switch (a.index()) {
           case 0:
               std::cout << std::get<0>(a) << '\n';
               break;
           case 1:
               std::cout << std::get<1>(a) << '\n';
               break;
           case 2:
               std::cout << std::get<2>(a) << '\n';
               break;
        }
    }
}