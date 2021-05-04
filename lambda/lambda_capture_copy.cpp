//
// Created by wq on 2021/5/2.
//

#include <iostream>

struct S2 {
public:
    void f(int i);

public:
    int j=0;
};

void S2::f(int i)
{
    [=]{j=i;}();    // OK: by-copy capture default
    std::cout << j << '\n';
    [=, &i]{};      // OK: by-copy capture, except i is captured by reference
    j = 0;
    [=, *this] ()mutable {j=i;}();   // until C++17: Error: invalid syntax
                                     // since c++17: OK: captures the enclosing S2 by copy
    std::cout << j << '\n';
    [=, this] {};   // until C++20: Error: this when = is the default
                    // since C++20: OK, same as [=]
}

int main(){
    S2 s;
    s.f(9);
}