//
// Created by 王强 on 2020/8/25.
//

#include <iostream>

const char *g() { return "dynamic initialization"; }
constexpr const char *f(bool p) { return p ? "constant initializer" : g(); }
/*
consteval int sqr(int n) {
    return n*n;
}*/

int main()
{
    const int a = 4;
    constexpr int b = a*a;

    printf("%d", b);
//    constexpr int r = sqr(100);  // OK

//    constinit const char *c = f(true); // OK
// constinit const char *d = f(false); // error
}