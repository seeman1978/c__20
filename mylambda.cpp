//
// Created by 王强 on 2020/9/11.
//
#include <vector>
#include <algorithm>
#include <iostream>
int main()
{
    std::vector<int> v {1,2,3};
    std::for_each(v.begin(), v.end(), [](int &n){ n*=n;});
    std::for_each(begin(v), end(v), [](int x){std::cout << " " << x;});

    std::for_each(v.begin(), v.end(), [](int &n){ n++; });
    std::for_each(begin(v), end(v), [](int x){ std::cout << " " << x++;});
    std::for_each(begin(v), end(v), [](int x){ std::cout << " " << x;});

    int i = 3;
    std::for_each(v.begin(), v.end(), [&i](const int &n){ i*=n;});
    std::cout << " i is  " << i;

}