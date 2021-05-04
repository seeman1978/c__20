//
// Created by wq on 2021/5/4.
//

#include <iostream>

int main()
{
    int m = 0;
    int n = 0;
    [&, n] (int a) mutable { m = ++n + a; }(4);
    std::cout << m << std::endl << n << std::endl;

    std::cout << [=]{int i=6; return m + n + i;}() << '\n';

    static int nextValue = 1;
    std::cout << [] { return ++nextValue; }() << '\n';
}