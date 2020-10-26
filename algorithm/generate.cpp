//
// Created by wq on 2020/10/25.
//

#include <algorithm>
#include <iostream>
#include <random>
#include <iterator>

int f(){
    static int i = 0;
    return ++i;
}

int main(){
    using namespace std;
    {
        vector<int> v(5);
        generate(v.begin(), v.end(), f);
        cout << "v1: ";
        for (auto iv: v){
            cout << iv << " ";
        }
        cout << '\n';
        generate(v.begin(), v.end(), [n=0]() mutable{return n++;});
        cout << "v2: ";
        for (auto iv : v){
            cout << iv << " " ;
        }
        cout << '\n';
    }
    {
        std::mt19937 rng; // default constructed, seeded with fixed seed
        std::generate_n(std::ostream_iterator<std::mt19937::result_type>(std::cout, " "),
                        5, std::ref(rng));
        std::cout << '\n';
    }
}