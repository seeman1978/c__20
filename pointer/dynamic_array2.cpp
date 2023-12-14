//
// Created by zhaoyue on 2020/11/25.
//

#include <string>
#include <iostream>
#include <memory>

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
    //std::shared_ptr<MyObject> pObj(new MyObject[i], [](MyObject* p){delete [] p;});
    //std::shared_ptr<MyObject> pObj(new MyObject[i]); // SIGABRT(Aborted). munmap_chunk(): invalid pointer
    std::shared_ptr<MyObject[]> pObj(new MyObject[i]);
    //为每个元素赋值
    for (size_t j=0; j < i; ++j){//智能指针不支持指针算术运算
        (pObj.get()+j)->m_str = "Hello";
    }

    for (size_t j=0; j < i; ++j){
        std::cout << (pObj.get()+j)->m_str << "\n";
    }
    //pObj.reset();//自动调用delete[]销毁其指针
}