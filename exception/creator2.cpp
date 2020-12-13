//
// Created by wq on 2020/12/13.
//

#include<iostream>

class B{

public:
    B(){
        std::cout << "construct B default" << std::endl;
        //throw 3; //故意在默认构造函数中抛出异常
    }
    explicit B(int num):m_nAge{num}{
        std::cout << "constructor B ,age =" << num << std::endl;
    }
    ~B(){
        std::cout << "destructor B ,age=" << m_nAge << std::endl;
    }
private:
    int m_nAge=0;
};

class A{
public:
    A():m_pData{new std::string("hello")}, m_b(B(10)), m_pB(new B()){
        std::cout << "construct A " << std::endl;
    }
    ~A(){
        std::cout << "destructor A" << std::endl;
        delete m_pData;
        delete m_pB;

    }
private:
    std::string* m_pData= nullptr;
    B m_b;
    B *m_pB;
};

int main(void){
    A a;
}