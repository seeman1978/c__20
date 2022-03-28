#include <chrono>
#include <iostream>
#include <csignal>

/**
* @file
* @brief
* @details
* @author		qiangwang
* @date		    2022/3/24
* @par Copyright(c): 	2022 mega. All rights reserved.
*/

int main(){
    std::cout << std::chrono::milliseconds(5000).count() << std::endl;
    usleep(std::chrono::milliseconds(50000000).count()*1000);
}
