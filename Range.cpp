//
// Created by zhaoyue on 2020/10/27.
//

#include <vector>
#include <iostream>
#include <ranges>

int main(){
    std::vector<int> ints{0,1,2,3,4,5};
    auto even = [](auto i){
        return 0==i%2;
    };
    auto square = [](auto i){
        return i*i;
    };
    for (auto i : ints | std::views::filter(even) | std::views::transform(square)){
        std::cout << i << "----------------\n";
    }
}