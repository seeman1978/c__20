//
// Created by 王强 on 2020/11/17.
//
#include <set>
#include <iostream>
#include <unordered_set>

int main()
{
    std::set<int> coll{3,1,5,4,1,6,2,3};
    for (auto i : coll){
        std::cout << i << ' ';
    }
    std::cout << '\n';

    for (auto i = coll.begin(); i != coll.end(); ++i) { //i is a const iterator
        //*i = 9;
        std::cout << *i << ' ';
    }
    std::cout << '\n';

    std::multiset<int> mcoll{3,1,5,4,1,6,2,3};
    for (auto i : mcoll){
        std::cout << i << ' ';
    }
    std::cout << '\n';

    std::unordered_multiset<int> umcoll{1,3,5,7,11,13,17,19,23,27,1};
    for (auto i : umcoll){
        std::cout << i << ' ';
    }
    std::cout << '\n';
}