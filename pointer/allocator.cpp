//
// Created by zhaoyue on 2020/11/25.
//

#include <string>
#include <iostream>

struct MyObject
{
    MyObject(){
        std::cout << " creator\n";
    }
    explicit MyObject(std::string str):m_str{std::move(str)}{
        std::cout << m_str << '\n';
    }
    ~MyObject(){
        std::cout << m_str << " destroy\n";
    }
    std::string m_str;
};

int main(){
    std::allocator<MyObject> allo;
    auto p = allo.allocate(3);  //分配3个MyObject的内存，每个MyObject未初始化
    for (int i = 0; i < 3; ++i) {
        allo.construct(p+i, "Hello");   //为了使用allocate返回的内存，我们必须用construct构造对象。
    }

    for (int i = 0; i < 3; ++i) {
        allo.destroy(p+i);
    }
    allo.deallocate(p, 3);
}