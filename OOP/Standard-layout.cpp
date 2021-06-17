//
// Created by 王强 on 2021/6/17.
//

#include <c++/v1/iostream>

// empty classes have standard-layout
struct StandardLayout1 {};

struct StandardLayout2 {
    int x;
};

struct StandardLayout3 {
private: // both are private, so it's ok
    int x;
    int y;
};

struct NonStandardLayout1 {
public:
    int x;
private: // one is public and another is private, so it's not ok.
    int y;
};

struct StandardLayout4 : StandardLayout1 {
    int x;
    int y;

    void f(){}; // perfectly fine to have non-virtual functions
};

struct StandardLayout5 : StandardLayout1 {
    int x;
    StandardLayout1 y; // can have members of base type if they're not the first member
};

// first member cannot be of the same type as base
struct NonStandardLayout2 : StandardLayout1 {
    StandardLayout1 y; // can have members of base type if they're the first member
    int x;
};

struct StandardLayout6 : StandardLayout1, StandardLayout2 {
    // can use multiple inheritance as long only
    // one class in the hierarchy has non-static data members
};

struct NonStandardLayout3 : StandardLayout1, StandardLayout3 {
    // can use multiple inheritance as long only
    // one class in the hierarchy has non-static data members
};

struct StandardLayout7 {
    int x;
    int y;
    StandardLayout7(int x, int y) : x(x), y(y) {} // user-provided ctors are ok
};

struct StandardLayout8 {
public:
    explicit StandardLayout8(int x) : x(x) {} // user-provided ctors are ok
// ok to have non-static data members and other members with different access
private:
    int x;
};

struct NonStandardLayout4 {
    virtual void f() {}; // cannot have virtual functions
};

struct StandardLayout9 {
    int x;
    static int y; // no restrictions on static members
};

struct StandardLayout10 {
    int x;
    static NonStandardLayout1 y; // no restrictions on static members
};

struct NonStandardLayout5 {
    NonStandardLayout1 X; // has non-standard-layout member
};

struct NonStandardLayout6 : StandardLayout2 {
    int z; // more than one class has non-static data members
};

struct NonStandardLayout7 : NonStandardLayout3 {}; // has a non-standard-layout base class

int main(){
    std::cout << std::is_standard_layout<StandardLayout1>::value << '\n';
    std::cout << std::is_standard_layout<StandardLayout2>::value << '\n';
    std::cout << std::is_standard_layout<StandardLayout3>::value << '\n';
    std::cout << std::is_standard_layout<NonStandardLayout1>::value << '\n';
    std::cout << std::is_standard_layout<StandardLayout4>::value << '\n';
    std::cout << std::is_standard_layout<StandardLayout5>::value << '\n';
    std::cout << std::is_standard_layout<NonStandardLayout2>::value << '\n';
    std::cout << std::is_standard_layout<StandardLayout6>::value << '\n';
    std::cout << std::is_standard_layout<NonStandardLayout3>::value << '\n';
    std::cout << std::is_standard_layout<StandardLayout7>::value << '\n';
    std::cout << std::is_standard_layout<StandardLayout8>::value << '\n';
    std::cout << std::is_standard_layout<NonStandardLayout4>::value << '\n';
    std::cout << std::is_standard_layout<StandardLayout9>::value << '\n';
    std::cout << std::is_standard_layout<StandardLayout10>::value << '\n';
    std::cout << std::is_standard_layout<NonStandardLayout5>::value << '\n';
    std::cout << std::is_standard_layout<NonStandardLayout6>::value << '\n';
    std::cout << std::is_standard_layout<NonStandardLayout7>::value << '\n';
}