//
// Created by zhaoyue on 2020/11/4.
//

#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>

int main()
{
    std::string s = "This is an example\n";
    std::copy(s.begin(), s.end(), std::ostreambuf_iterator<char>(std::cout));
}