//
// Created by 王强 on 2020/2/24.
//
#include <iostream>

struct S {
    int x1 : 2;
    volatile double y1;
};

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
    std::tuple<int, double, std::string> ids;
    ids = std::make_tuple(1, 2.5, "hello world");
    const auto& [id, score, name] = ids;

    std::cout << "id is " << id << ". score is " << score << ". name is " << name << "." << std::endl;

    /// 绑定到数据成员
    const auto [x1, y1] = S();
    std::cout << "x1 is " << x1 << ". y1 is " << y1 << std::endl;
}