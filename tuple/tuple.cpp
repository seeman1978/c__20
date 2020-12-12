//
// Created by wq on 2020/12/12.
//

#include <iostream>
#include <tuple>
#include <vector>

int main()
{
    std::vector<std::tuple<int, std::string, float>> v;
    v.emplace_back(2, "baz", -0.1);
    v.emplace_back(2, "bar", 3.14);
    v.emplace_back(1, "foo", 100.1);
    std::sort(v.begin(), v.end());

    for(auto p: v) {
        std::cout << "(" << std::get<0>(p) << ", " << std::get<1>(p)
                  << ", " << std::get<2>(p) << ")\n";
    }

    for (auto [id, name, value] : v){
        std::cout << "(" << id << ", " << name
                  << ", " << value << ")\n";
    }
}