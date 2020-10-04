//
// Created by zhaoyue on 2020/10/4.
//

#include <iostream>

class A{
public:
    void f(){
        std::cout << "f() in class A " << std::endl;
    }
protected:
    void g(){
        std::cout << "g() in class A " << std::endl;
    }
};

class B : public A{
public:
    void f2(){
        std::cout << "f2() in class B " << std::endl;
        f();
        g();
    }
};

class AA{
public:
    void f(){
        std::cout << "f() in class AA " << std::endl;
    }

protected:
    void g(){
        std::cout << "g() in class AA " << std::endl;
    }
};

class BB : protected AA{
public:
    void f2(){
        std::cout << "f2() in class BB " << std::endl;
        f();
        g();
    }
};

class CC: protected BB{
public:
    void f3(){
        std::cout << "f3() in class CC " << std::endl;
        f();
        g();
        f2();
    }
};

class AAA{
public:
    void f(){
        std::cout << "f() in class AAA " << std::endl;
    }

protected:
    void g(){
        std::cout << "g() in class AAA " << std::endl;
    }
};

class BBB : private AAA{
public:
    void f2(){
        std::cout << "f2() in class BBB " << std::endl;
        f();
        g();
    }
};

class CCC : private BBB{
public:
    void f3(){
        std::cout << "f3() in class CCC " << std::endl;
        //f();  //不可见
        //g();  //不可见
        f2();
    }
};

int main(){
    B b;
    b.f2();
    b.f();

    //父类的public方法不可见
    BB bb;
    bb.f2();

    CC cc;
    cc.f3();

    BBB bbb;
    bbb.f2();

    CCC ccc;
    ccc.f3();
}