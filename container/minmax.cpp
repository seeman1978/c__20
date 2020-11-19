//
// Created by 王强 on 2020/11/17.
//

#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v {3, 1, 4, 1, 5, 9, 2, 6};

    const auto [min, max] = std::minmax_element(v.begin(), v.end());

    std::cout << "min = " << *min << ", max = " << *max << '\n';
}