//
// Created by wq on 2021/5/23.
//

#include <vector>
#include <iostream>

int main(){
    {
        std::vector<int> vec{1, 2, 3, 4, 3, 5, 6};
        std::vector<int>::iterator pos;
        for (pos=vec.begin();pos!=vec.end();) {
            if (*pos == 3){
                vec.erase(pos);
            }
            else{
                ++pos;
            }
        }
        for (auto x: vec) {
            std::cout << x << ' ';
        }
        std::cout << '\n';
    }

    {
        std::vector<int> vec{1, 2, 3, 4, 3, 5, 6};
        vec.erase(std::remove_if(vec.begin(), vec.end(),
                               [](int x){return x==3;}),
                vec.end());
        for (auto x: vec) {
            std::cout << x << ' ';
        }
        std::cout << '\n';
    }
}