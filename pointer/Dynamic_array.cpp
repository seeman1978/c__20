//
// Created by zhaoyue on 2020/11/25.
//

#include <string>
#include <iostream>

struct MyObject
{
    MyObject()=default;
    explicit MyObject(std::string str):m_str{std::move(str)}{

    }
    ~MyObject(){
        std::cout << m_str << " destroy\n";
    }
    std::string m_str;
};

int main(){
    size_t i = 3;
    std::unique_ptr<MyObject[]> up {new MyObject[i]};
    //为每个元素赋值
    for (size_t j=0; j < i; ++j){
        up[j].m_str = "Hello";
    }

    for (size_t j=0; j < i; ++j){
        std::cout << up[j].m_str << "\n";
    }

    //up.reset();//自动调用delete[]销毁其指针
}