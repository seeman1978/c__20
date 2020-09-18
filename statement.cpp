//
// Created by zhaoyue on 2020/9/8.
//

#include <iostream>

void f(int i)
{
    if (i)
        int x = i + 2;
}

int main()
{
    bool b ;
    if(b)
        int i = 9;

    if (int m=0)
    {
        int j = 9;
    } else{
        int k = 10;
        //int m = 11;   //redefinition
    }
    auto p = new int;
    std::cout << "pointer is " << p << ". point is " << *p << std::endl;
    delete p;
    delete p;
}