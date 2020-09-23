//
// Created by zhaoyue on 2020/9/22.
//
#include <iostream>

namespace {
    int a = 9;
    void f(){
        std::cout << "namespace hello" << std::endl;
    }
}

namespace test{
    void f(){
        std::cout << "hello" << std::endl;
    }
}

namespace N {
    template <class T>
    void f(T, int i)
    {
        std::cout << "N::f:i:" << i << std::endl;
    }

    void f2(int i)
    {
        std::cout << "N::f2:i:" << i << std::endl;
    }

    int j = 9;

    class X{};
}

namespace N2 {
    N::X x;
    void f(N::X, unsigned int i){
        std::cout << "N2::f:i:" << i << std::endl;
    }

    void f2(unsigned int i){
        std::cout << "N2::f2:i:" << i << std::endl;
    }

    void g() {
        f(x, 1);    //参数依赖查找，会调用N::f，而不是N2::f
        f2(18);
        int m;
        std::cout << "m value is " << m << std::endl;
    }
}

int main()
{
    f();
    ::f();
    test::f();

    N2::g();
}