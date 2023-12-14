//
// Created by wq on 23-12-14.
//


#include <memory>
#include <iostream>

std::unique_ptr<int> foo()
{
    std::unique_ptr<int> p( new int(10) );

    return p;                   // 1
    //return move( p );         // 2
}

int main()
{
    std::unique_ptr<int> p = foo();

    std::cout << *p << std::endl;
    return 0;
}