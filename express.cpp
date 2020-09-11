//
// Created by 王强 on 2020/9/8.
//
#include <vector>
#include <iostream>

int main()
{
    int i=1;
    std::vector<int> vec{1,2,3};

    vec[i] = i++;   //求值顺序

    for (const auto& x : vec)
        std::cout << "vec " << x << std::endl;
}