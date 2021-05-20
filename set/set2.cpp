//
// Created by zhaoyue on 2021/5/20.
//

#include <set>
#include <iostream>

int main(){
    std::set<int> s{1, 2, 3, 4, 5, 6};
    std::set<int>::iterator pos;
    for (pos=s.begin();pos!=s.end();) {
        if (*pos == 3){
            pos = s.erase(pos);
        }
        else{
            ++pos;
        }
    }
    for (auto x: s) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}