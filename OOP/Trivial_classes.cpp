//
// Created by 王强 on 2021/6/17.
//
#include <iostream>

//empty classes are trivial
struct t1{};

//all special members are implicit
struct t2{
    t2()=default;
    explicit t2(int i):x{i}{};
    int x;
};
struct nont2{
    int x=0;
};

//base class is trivial
struct t3 : t2{
    t3()=default; //not a user-provided ctor
    int y;
};
//base class is trivial
struct nont3 : t2{
    nont3(){

    };
    int y;
};

struct t4 : t2{
    t4()=default;   // not user-provided
    // a regular constructor is okay because we still have default ctor
    explicit t4(int i, int j): t2(i), y{j}{

    }
    int y;
};

struct t5 {
public:
    int a;
private: // no restrictions on access modifiers
    int b;
};

struct t6 {
    t3 a;
    t5 b;
};

struct t7 {
    t2 a[23];
};

struct t8 {
    t6 c;
    void f(){}; // it's okay to have non-virtual functions
};

struct nont9{
    nont3 d;
};

// virtual members make non-trivial ctors
struct nont10{
    virtual void f(){

    }
};

// no restrictions on static members
struct t11{
    int x;
    static nont10 t;
};

// virtual destructors are not trivial
struct nont12 {
    virtual ~nont12(); // virtual destructors are not trivial
};
int main(){
    std::cout << std::is_trivial<t1>::value << '\n';
    std::cout << std::is_trivial<t2>::value << '\n';
    std::cout << std::is_trivial<nont2>::value << '\n';
    std::cout << std::is_trivial<t3>::value << '\n';
    std::cout << std::is_trivial<nont3>::value << '\n';
    std::cout << std::is_trivial<t4>::value << '\n';

    std::cout << std::is_trivial<t5>::value << '\n';
    std::cout << std::is_trivial<t6>::value << '\n';
    std::cout << std::is_trivial<t7>::value << '\n';
    std::cout << std::is_trivial<t8>::value << '\n';
    std::cout << std::is_trivial<nont9>::value << '\n';
    std::cout << std::is_trivial<nont10>::value << '\n';
    std::cout << std::is_trivial<t11>::value << '\n';
    std::cout << std::is_trivial<nont12>::value << '\n';
}