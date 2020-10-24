//
// Created by wq on 2020/10/24.
//

#include <algorithm>
#include <iostream>

int main(){
    using namespace std;
    vector<int> v{1, 2, 3};
    reverse(v.begin(), v.end());
    for (auto e : v){
        std::cout << e << ' ';
    }
    cout << '\n';

    std::vector<int> destination;

    reverse_copy(v.begin(), v.end(), back_inserter(destination));

    for (auto e : destination){
        std::cout << e << ' ';
    }
    cout << '\n';
}
