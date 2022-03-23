#include <random>
#include <iostream>

/**
* @file
* @brief
* @details
* @author		qiangwang
* @date		    2022/3/23
* @par Copyright(c): 	2022 mega. All rights reserved.
*/

int main(){
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<uint32_t> dis(0, 100);
    uint32_t a = dis(mt);
    std::cout << a << '\n';

    std::uniform_int_distribution<uint32_t> dis1(0, a+100);
    uint32_t a1 = dis1(mt);
    std::cout << a1 << '\n';

    std::uniform_int_distribution<uint32_t> dis2(0, a1+100);
    uint32_t a2 = dis2(mt);
    std::cout << a2 << '\n';
}

//int main(){
//    std::random_device rd;
//    std::mt19937 mt(rd());
//    std::uniform_int_distribution<uint32_t> dis(0, 100);
//    uint32_t a = dis(mt);
//    std::cout << a << '\n';
//
//    std::random_device rd1;
//    std::mt19937 mt1(rd1());
//    std::uniform_int_distribution<uint32_t> dis1(0, a);
//    uint32_t a1 = dis1(mt1);
//    std::cout << a1 << '\n';
//
//    std::random_device rd2;
//    std::mt19937 mt2(rd2());
//    std::uniform_int_distribution<uint32_t> dis2(0, a1);
//    uint32_t a2 = dis2(mt2);
//    std::cout << a2 << '\n';
//}