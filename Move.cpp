//
// Created by 王强 on 2020/2/28.
//

#include <string>
#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>

struct A
{
    std::string s;
    int k;
    A() : s("test"), k(-1) { std::cout << "a" << std::endl;}
    A(const A& o) : s(o.s), k(o.k) { std::cout << "move failed!\n"; }
    A(A&& o) noexcept :
            s(std::move(o.s)),       // 类类型成员的显式移动
            k(std::exchange(o.k, 0)) // 非类类型成员的显式移动
    {std::cout << "b" << std::endl; }
};

A f(A a)
{
    return a;   /// 触发右值拷贝
}

struct B : A
{
    std::string s2;
    int n;
    // 隐式移动构造函数 B::(B&&)
    // 调用 A 的移动构造函数
    // 调用 s2 的移动构造函数
    // 并进行 n 的逐位复制
};

struct C : B
{
    ~C() { } // 析构函数阻止隐式移动构造函数 C::(C&&)
};

struct D : B
{
    D() { }
    ~D() { }          // 析构函数阻止隐式移动构造函数 D::(D&&)
    D(D&&) = default; // 强制生成移动构造函数
};

int main()
{
    std::string str = "Hello";
    std::vector<std::string> v;
    //调用常规的拷贝构造函数，新建字符数组，拷贝数据
    v.push_back(str);
    std::cout << "After copy, str is \"" << str << "\"\n";
    //调用移动构造函数，掏空str，掏空后，最好不要使用str
    v.push_back(std::move(str));
    std::cout << "After move, str is \"" << str << "\"\n";
    std::cout << "The contents of the vector are \"" << v[0]
              << "\", \"" << v[1] << "\"\n";

    std::cout << "Trying to move A\n";
    A a1 = f(A()); // 按值返回时，从函数形参移动构造其目标

    std::cout << "Before move, a1.s = " << std::quoted(a1.s) << " a1.k = " << a1.k << '\n';
    A a2 = std::move(a1); // 从亡值移动构造

    std::cout << "After move, a1.s = " << std::quoted(a1.s) << " a1.k = " << a1.k << '\n';

    std::cout << "Trying to move B\n";
    B b1;
    std::cout << "Before move, b1.s = " << std::quoted(b1.s) << "\n";

    B b2 = std::move(b1); // 调用隐式移动构造函数
    std::cout << "After move, b1.s = " << std::quoted(b1.s) << "\n";

    std::cout << "Trying to move C\n";
    C c1;
    C c2 = std::move(c1); // 调用复制构造函数

    std::cout << "Trying to move D\n";
    D d1;
    D d2 = std::move(d1);

}