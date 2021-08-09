//
// Created by qiangwang on 2021/8/9.
//

#include <string>

struct A{
    int i;
    std::string str;
};

struct B{
    std::uint32_t i;
    std::string str;
};

int main(){
    A a{1, "hello"};
    B b{1, "hello"};
}