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
    printf("byte length:%lu\n", sizeof(std::byte));
    printf("char length:%lu\n", sizeof(char));
    printf("bool length:%lu\n", sizeof(bool));
    printf("short length:%lu\n", sizeof(short));
    printf("int length:%lu\n", sizeof(int));
    printf("long length:%lu\n", sizeof(long));
    printf("long long length:%lu\n", sizeof(long long));
    printf("float length:%lu\n", sizeof(float));
    printf("double length:%lu\n", sizeof(double));
    printf("long double length:%lu\n", sizeof(long double));
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

    int arrInt[5]{1,2,3,4,5};
    int* pI2 = arrInt;
    std::cout << "array size : " << sizeof(pI2) << ". element cout is " << sizeof(pI2)/sizeof(pI2[0])<< '\n';   //error
    std::cout << "array size : " << sizeof(arrInt) << ". element cout is " << sizeof(arrInt)/sizeof(arrInt[0])<< '\n';  //true
    int* pI = new int[5]{1,2,3,4,5};
    std::cout << "array size : " << sizeof(pI) << ". element cout is " << sizeof(pI)/sizeof(pI[0])<< '\n';   //error

}