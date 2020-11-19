//
// Created by 王强 on 2020/11/19.
//
#include <list>
#include <vector>
#include <iostream>

int main(){
    std::list<std::string> l{"wang", "qiang"};
    std::vector<std::string> c(std::make_move_iterator(l.begin()), std::make_move_iterator(l.end()));
    for (auto& var : c){
        std::cout << var << ' ';
    }
    std::cout << '\n';
    for (auto& var : l){
        std::cout << var << ' ';
    }
}
