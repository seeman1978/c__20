#include <string>
#include <vector>

/**
* @file
* @brief
* @details
* @author		qiangwang
* @date		    2022/4/6
* @par Copyright(c): 	2022 mega. All rights reserved.
*/
struct test{
    std::string str;
    int i;
};
int main(){
    std::vector<test> vec;
    vec.emplace_back("hello", 1);   //only for c++20
    vec.emplace_back(test{"hello", 1});
}