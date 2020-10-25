//
// Created by wq on 2020/1;;l;lll/24.
//

#include <vector>
#include <iostream>
#include <algorithm>obstack
int main()
{
    {
        std::vector<int> v{2, 4, 2, 0, 5, 10, 7, 3, 7, 1};

        std::cout << "before sort:\t\t";
        for (int n: v)
            std::cout << n << ' ';
        std::cout << '\n';

        // insertion sort
        for (auto i = v.begin(); i != v.end(); ++i) {
            std::rotate(std::upper_bound(v.begin(), i, *i), i, i+1);
        }

        std::cout << "after sort:\t\t";
        for (int n: v)
            std::cout << n << ' ';
        std::cout << '\n';

        // simple rotation to the left
        std::rotate(v.begin(), v.begin() + 1, v.end());

        std::cout << "simple rotate left:\t";
        for (int n: v)
            std::cout << n << ' ';
        std::cout << '\n';

        // simple rotation to the right
        std::rotate(v.rbegin(), v.rbegin() + 3, v.rend());

        std::cout << "simple rotate right:\t";
        for (int n: v)
            std::cout << n << ' ';
        std::cout << '\n';
    }

    {
        std::vector<int> src = {1, 2, 3, 4, 5};
        auto pivot = std::find(src.begin(), src.end(), 3);
        std::vector<int> dest(src.size());

        std::rotate_copy(src.begin(), pivot, src.end(), dest.begin());

        for (const auto &i : dest) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }

}