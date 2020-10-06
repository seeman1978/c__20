//
// Created by 王强 on 2020/10/6.
//

#include <iostream>
#include <typeinfo>
#include <typeindex>

class Base {
public:
    virtual void vvfunc() {}
};

class Derived : public Base {};

class A{};

using namespace std;
int main() {
    Derived* pd = new Derived;
    Base* pb = pd;
    cout << typeid( pb ).name() << endl;   //prints "class Base *"
    cout << typeid( *pb ).name() << endl;   //prints "class Derived"
    cout << typeid( pd ).name() << endl;   //prints "class Derived *"
    cout << typeid( *pd ).name() << endl;   //prints "class Derived"
    delete pd;

    A a;
    A& rA {a};
    const std::type_info& ti1 = typeid(a);
    const std::type_info& ti2 = typeid(a);
    assert(&ti1 == &ti2); // not guaranteed
    assert(ti1.hash_code() == ti2.hash_code()); //guaranteed
    assert(std::type_index(ti1) == std::type_index(ti2));      //guaranteed
}