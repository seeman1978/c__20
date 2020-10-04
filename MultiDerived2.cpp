//
// Created by zhaoyue on 2020/10/4.
//

#include <iostream>

class A{
public:
    void f(){
        std::cout << "f() in class A" << std::endl;
    }

private:
    int m_i = 19;
};

class B: public A{

};

class C: public A{

};

class D: public B, public C{

};

class BB: public virtual A{

};

class CC: public virtual A{

};

class DD: public BB, public CC{

};


int main(){
    D d;
    std::cout << sizeof(d) << std::endl;    //8

    DD dd;
    std::cout << sizeof(dd) << std::endl;   //24 因为要保存虚函数表指针
}

