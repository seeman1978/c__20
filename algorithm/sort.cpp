//
// Created by zhaoyue on 2020/10/26.
//

#include <array>
#include <iostream>

template<typename T>
void print(const T& s){
    for(auto a : s){
        std::cout << a << ' ';
    }
    std::cout << '\n';
}

int main(){
    using namespace std;
    {
        array<int, 10> s {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
        sort(s.begin(), s.end());
        print(s);

        sort(s.begin(), s.end(), greater<int>());
        print(s);

        struct {
            bool operator()(int a, int b) const{
                return a<b;
            }
        } customLess;
        sort(s.begin(), s.end(), customLess);
        print(s);

        sort(s.begin(), s.end(),[](int a, int b){return a>b;});
        print(s);
    }
}