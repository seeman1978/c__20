//
// Created by 王强 on 2020/10/6.
//

#include <iostream>
#include <typeinfo>

class Base {
public:
    virtual void vvfunc() {}
};

class Derived : public Base {};

using namespace std;
int main() {
    Derived* pd = new Derived;
    Base* pb = pd;
    cout << typeid( pb ).name() << endl;   //prints "class Base *"
    cout << typeid( *pb ).name() << endl;   //prints "class Derived"
    cout << typeid( pd ).name() << endl;   //prints "class Derived *"
    cout << typeid( *pd ).name() << endl;   //prints "class Derived"
    delete pd;
}