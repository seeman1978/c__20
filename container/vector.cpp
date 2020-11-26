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
    A(int i, const std::string& str){
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
    {//效率更高
        vector<A> v1;
        v1.reserve(5);  //不会构造5个对象A。另外不能使用reserve缩减内存
    }
}