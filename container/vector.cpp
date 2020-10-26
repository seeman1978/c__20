//
// Created by wq on 2020/10/26.
//

#include <string>
#include <vector>
#include <iostream>

struct A{
    int i {9};
    std::string str {"hello"};
    A():i{10}, str{"world"}{}
    A(int i, const std::string str){
        this->i = i;
        this->str = str;
    }
};

int main(){
    using namespace std;
    {
        vector<A> v1(5);   //调用默认构造函数
        for (auto& a : v1){
            cout << a.i << " " << a.str << '\n';
        }

        vector<A> v2(3, {2, "lala"});
        for (auto& a : v2){
            cout << a.i << " " << a.str << '\n';
        }
    }
}