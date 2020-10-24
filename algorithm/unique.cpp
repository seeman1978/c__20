//
// Created by wq on 2020/10/24.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>

//unique删除连续的重复元素
//重复由BinaryPredicate定义
int main()
{
    // a vector containing several duplicate elements
    std::vector<int> v{1,2,1,1,3,3,3,4,5,4};

    // remove consecutive (adjacent) duplicates
    auto last = std::unique(v.begin(), v.end());
    // v now holds {1 2 1 3 4 5 4 x x x}, where 'x' is indeterminate
    for (int i : v)
        std::cout << i << " ";
    std::cout << "\n";
    v.erase(last, v.end());
    for (int i : v)
        std::cout << i << " ";
    std::cout << "\n";

    // sort followed by unique, to remove all duplicates
    std::sort(v.begin(), v.end()); // {1 1 2 3 4 4 5}
    last = std::unique(v.begin(), v.end());
    // v now holds {1 2 3 4 5 x x}, where 'x' is indeterminate
    v.erase(last, v.end());
    for (int i : v)
        std::cout << i << " ";
    std::cout << "\n";

    {
        std::string s1 = "The      string    with many       spaces!";
        std::cout << "before: " << s1 << '\n';

        std::string s2;
        std::unique_copy(s1.begin(), s1.end(), std::back_inserter(s2),
                         [](char c1, char c2){ return c1 == ' ' && c2 == ' '; });

        std::cout << "after:  " << s2 << '\n';
    }
}