//
// Created by zhaoyue on 2020/11/19.
//
#include <set>
#include <deque>
#include <iostream>
#include <algorithm>

template<typename T>
void printcontainer(const T& t){
    for (auto var:t){
        std::cout << var << ' ';
    }
    std::cout << '\n';
}

int main(){
    std::set<int, std::greater<int>> coll1{1,2,3,4,5,6,7,8,9};
    printcontainer(coll1);

    std::deque<int> coll2;

    std::transform(coll1.cbegin(), coll1.cend(), std::back_inserter(coll2),
            std::bind(std::multiplies<int>(), std::placeholders::_1, 10));
    printcontainer(coll2);

    std::replace_if(coll2.begin(), coll2.end(),
            std::bind(std::equal_to<int>(), std::placeholders::_1, 70), 42);
    printcontainer(coll2);

    coll2.erase(std::remove_if(coll2.begin(), coll2.end(),
            std::bind(std::logical_and<bool>(),
                    std::bind(std::greater_equal<int>(), std::placeholders::_1, 50),
                    std::bind(std::less_equal<int>(), std::placeholders::_1, 80))),
                            coll2.end());
    printcontainer(coll2);
}