//
// Created by zhaoyue on 2020/11/19.
//
#include <vector>
#include <iostream>
int main(){
    {
        std::vector<std::string> v1{"Hello", "World"};

        for (auto var=v1.rbegin(); var != v1.rend(); ++var){
            std::cout << *var << ' ';
        }
        std::cout << '\n';
    }
    {
        std::string line{"first,second,last"};
        auto rcomma = std::find(line.crbegin(), line.crend(), ',');
        std::cout << std::string(line.crbegin(), rcomma);   //注意输出tsal
    }
}
