//
// Created by wq on 2020/12/13.
//

#include <string>
#include <iostream>
//构造函数发生异常，对象没有被成功创建，则不会执行析构函数。
struct A{
    A(){
        m_pInt = new int(5);
        std::cout << *m_pStr;
        m_pStr = new std::string{"hello"};
    }

    ~A(){
        if (m_pInt != nullptr){
            delete m_pInt;
            m_pInt = nullptr;
        }
        if (m_pStr != nullptr){
            delete m_pStr;
            m_pStr = nullptr;
        }
    }

private:
    int* m_pInt= nullptr;
    std::string* m_pStr= nullptr;
};

int main(){
    try {
        A a;
    }
    catch(...){
        std::cout << "exception happened.";
    }
}