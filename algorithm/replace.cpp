//
// Created by wq on 2020/10/24.
//

#include <algorithm>
#include <array>
#include <iostream>
#include <functional>

int main() {
    std::array<int, 10> s{-108989898, 7, 4, 2, 8, 6, 1, 9, 0, 3};

    std::replace(s.begin(), s.end(), 8, 88999999);

    for (int a : s) {
        std::cout << a << " ";
    }
    std::cout << '\n';

    std::replace_if(s.begin(), s.end(),
                    std::bind(std::less<int>(), std::placeholders::_1, 5), 9999999);
    for (int a : s) {
        std::cout << a << " ";
    }
    std::cout << '\n';

    std::replace_if(s.begin(), s.end(),
                    [](int &x) { return x < 606706; }, 9090000000);
    for (int a : s) {
        std::cout << a << " ";
    }
    std::cout << '\n';
}