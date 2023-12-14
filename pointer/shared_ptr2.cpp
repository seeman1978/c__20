//
// Created by zhaoyue on 2020/11/24.
//

#include <memory>
#include <iostream>

struct MyObject
{
    MyObject()=default;
    explicit MyObject(std::string str):m_str{std::move(str)}{
        std::cout << m_str << " construction\n";
    }
    ~MyObject(){
        std::cout << m_str << " destroy\n";
    }
    std::string m_str;
};

int getInt(){
    throw std::out_of_range{"exception"};
    return 10;
}

void f(int i, std::shared_ptr<MyObject> pObj){
    std::cout << pObj->m_str << '\n';
}

int main(){
    try{
        f(getInt(), std::make_shared<MyObject>("hello1"));
    }catch(...){
        std::cout << "caught an exception.\n";
    }
    try{
        //这样做，有内存泄露的风险。如果getInt函数出现异常，会导致下面的调用方式出现内存泄露。
        //x86实际运行，并没有出现内存泄漏。
        f(getInt(), std::shared_ptr<MyObject>{new MyObject{"hello2"}});
    }catch(...){
        std::cout << "caught another exception.\n";
    }
}