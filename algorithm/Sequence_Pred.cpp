//
// Created by wq on 2020/10/24.
//

#include <vector>
#include <numeric>
#include <iostream>
#include <iterator>
#include <functional>

int main(){
    using namespace std;
    vector<int> v(10,2);
    partial_sum(v.cbegin(), v.cend(), v.begin());   // 累积求和
    std::cout << "Among the numbers: ";
    copy(v.cbegin(), v.cend(), ostream_iterator<int>(cout, " "));
    cout << '\n';

    if (all_of(v.cbegin(), v.cend(), [](int i){ return i%2 == 0;})){
        std::cout << "All numbers are even\n";
    }
    //std::modulus::operator() modulus模板类，取余
    if (std::none_of(v.cbegin(), v.cend(), bind(modulus<int>(), placeholders::_1, 2))){
        cout << "None of them are odd\n";
    }

    struct DivisibleBy{
        const int d;
        DivisibleBy(int n):d(n){}
        bool operator()(int n) const{return n%d == 0;}
    };

    if (std::any_of(v.cbegin(), v.cend(), DivisibleBy(7))){
        std::cout << "At least one number is divisible by 7\n";
    }

}