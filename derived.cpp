//
// Created by zhaoyue on 2020/9/25.
//

#include <iostream>

class C{
public:
    C(){
        std::cout << "class C " << std::endl;
    }

    virtual ~C(){
        std::cout << "class C destroy " << std::endl;
    }
};

class D{
public:
    D(){
        std::cout << "class D " << std::endl;
    }

    virtual ~D(){
        std::cout << "class D destroy " << std::endl;
    }
};

class A{
public:
    A(){
        std::cout << "class A 1 " << std::endl;
    }
    explicit A(int i):m_i{i}{
        std::cout << "class A 2 " << std::endl;
    }

    virtual ~A(){
        std::cout << "class A destroy " << std::endl;
    }

protected:
    int m_i;
};

class B: A{
public:
    B(){
        std::cout << "class B 1 " << std::endl;
    }
    explicit B(int j):m_j{j},m_d{},m_c{}{   //class A中的m_i未初始化
        std::cout << "class B 2 " << std::endl;
    }

    virtual ~B(){
        std::cout << "class B destroy " << std::endl;
    }
    void f(){
        std::cout << "B.m_j " << m_j << std::endl
        << "A.m_i " << m_i << std::endl;
    };
private:
    int m_j;
    C m_c;
    D m_d;
};

int main(){
    B b(10);
    b.f();
}