// C++数据类型长度
// Created by 王强 on 2020/8/25.
//
#include <iostream>
#include <string>

class CA
{};

class CB
{
    int m_i;
};

struct  s{int x; std::string str;};

void f()
{
    int x;
    printf("uninit value is %d\n", x);
}

int main()
{
    printf("char length:%d\n", sizeof(char));
    printf("int length:%d\n", sizeof(int));
    printf("double length:%d\n", sizeof(double));
    CA a;
    printf("Class A length:%d\n", sizeof(CA));

    CB b;
    printf("Class B length:%d\n", sizeof(b));

    std::unique_ptr<int> p {new int{9} };
    printf("pointer length is %d\n", sizeof(p));

    char ch;
    int m = ch;
    printf("integer is %d. char is %c.\n", m, ch);

    int ;   //变量可以没有名字

    for (int n=0; n<2; ++n)
    {
        ;
    }

    //n = 9;    //undeclared identifier 'n'

    int h;  //未初始化，默认值是0
    printf("uninit is %d\n", h);

    f();

    struct s temp {1, "hello"};
}