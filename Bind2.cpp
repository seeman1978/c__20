//
// Created by zhaoyue on 2020/10/19.
//

#include <iostream>
#include <random>

void f(int n1, int n2, int n3, const int& n4, int n5)
{
    std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << '\n';
}

int g(int n1){
    return ++n1;
}

struct Foo{
    void print_sum(int n1, int n2){
        std::cout << n1 +  n2 << '\n';
    }
    int data = 10;
};

int main(){
    using namespace std::placeholders;
    int n= 7;
    // demonstrates argument reordering and pass-by-reference
    // (_1 and _2 are from std::placeholders, and represent future
    // arguments that will be passed to f1)
    auto f1 = std::bind(f, _2, 42, _1, std::cref(n), n);

    n = 10;
    // 1 is bound by _1, 2 is bound by _2, 1001 is unused
    // makes a call to f(2, 42, 1, n, 7)
    f1(1, 2, 10001);    //?n是7还是10？因为std::cref(n)是指向变量n的引用，当n值发生变化时，该参数的值也相应发生变化
    // nested bind subexpressions share the placeholders
    auto f2 = std::bind(f, _3, std::bind(g, _3), _3, 4, 5);

    f2(10, 11, 12); //makes a call to f(12, g(12), 12, 4, 5);

    // common use case: binding a RNG with a distribution
    std::default_random_engine e;
    std::uniform_int_distribution<> d(0, 10);
    auto rnd = std::bind(d, e);
    for(int m=0; m<10; ++m){
        std::cout << rnd() << " ";
    }
    std::cout << '\n';

    // bind to a pointer to member function
    Foo foo;
    auto f3 = std::bind(&Foo::print_sum, &foo, 95, _1);
    f3(5);
    auto f33 = std::bind(&Foo::print_sum, foo, 15, _1);
    f33(25);


    // bind to a pointer to data member
    auto f4 = std::bind(&Foo::data, _1);
    std::cout << f4(&foo) << '\n'
        << f4(foo) << '\n';

    // smart pointers can be used to call members of the referenced objects, too
    std::cout << f4(std::make_shared<Foo>(foo)) << '\n'
              << f4(std::make_unique<Foo>(foo)) << '\n';
}