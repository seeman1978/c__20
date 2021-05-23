//
// Created by zhaoyue on 2021/5/20.
//

#include <set>
#include <iostream>

int main(){
    {
        std::set<int> s{1, 2, 3, 4, 3, 5, 6};
        std::set<int>::iterator pos;
        for (pos=s.begin();pos!=s.end();) {
            if (*pos == 3){
                pos = s.erase(pos);
                //s.erase(pos); //程序异常
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
    /*{
        std::set<int> s{1, 2, 3, 4, 3, 5, 6};
        s.erase(std::remove_if(s.begin(), s.end(),
                               [](int x){return x==3;}),
                s.end());
        for (auto x: s) {
            std::cout << x << ' ';
        }
        std::cout << '\n';
    }*/
    {
        std::set<int> s{1, 2, 3, 4, 3, 5, 6};
        std::erase_if(s, [](auto x){return x==3;});
        for (auto x: s) {
            std::cout << x << ' ';
        }
        std::cout << '\n';
    }
}