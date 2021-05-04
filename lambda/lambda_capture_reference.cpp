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
    int m = 0;
    [&]{m=i;}();          // OK: by-reference capture default
    std::cout << m << '\n';
    [&, i]{};       // OK: by-reference capture, except i is captured by copy
    //[&, &i] {};     // Error: by-reference capture when by-reference is the default
    [&, this] {};   // OK, equivalent to [&]

    [&, *this]() mutable {this->j = i;}();  // OK, by-reference capture, except this is captured by copy
    std::cout << j << '\n';

    [&, this, i]{this->j = i;}(); // OK, equivalent to [&, i]
    std::cout << j << '\n';
}

int main(){
    S2 s;
    s.f(9);
}