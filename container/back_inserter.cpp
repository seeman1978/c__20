//
// Created by 王强 on 2020/11/17.
//

#include <list>
#include <vector>
#include <algorithm>
#include <deque>
#include <set>
#include <iostream>

template <typename T>
void printT(const T& t){
    for (auto i : t){
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

int main(){
    std::list<int> coll1{1,2,3,4,5,6,7,8,9};
    std::vector<int> coll2;
    std::copy(coll1.begin(), coll1.end(), std::back_inserter(coll2));
    printT(coll2);
    std::deque<int> coll3;
    std::copy(coll1.begin(), coll1.end(), std::front_inserter(coll3));
    printT(coll3);
    std::set<int> coll4;
    std::copy(coll1.begin(), coll1.end(), std::inserter(coll4, coll4.begin()));
    printT(coll4);
}