//
// Created by 王强 on 2020/2/24.
//
#include <iostream>
int main()
{
    /// 绑定数组
    int a[3] = {1,2,3};

    auto [x,y,z] = a;
    std::cout << "x is " << x << ". y is " << y << std::endl;

    auto& [xr, yr, zr] = a;

    xr = 4;

    std::cout << "a[0] is " << a[0] << std::endl;

    /// 绑定元祖式
}