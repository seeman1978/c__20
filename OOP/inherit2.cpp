//
// Created by 王强 on 2020/12/3.
//

#include <string>
#include <iostream>
#include <vector>

struct A{
    A()=default;
    A(int i, std::string str):m_i{i}, m_str{std::move(str)}{

    }

    virtual void func(){
        std::cout << "I am A." << m_str << " " << m_i << '\n';
    }

protected:
    int m_i=0;
    std::string m_str;
};

struct B : public A{
    using A::A;
    void func() override{
        std::cout << "I am B." << m_str << " " << m_str2 << " " << m_i << '\n';
    }

private:
    std::string m_str2{"world"};
};

struct C : public A{
    //对于基类的每个构造函数，编译器都在派生类中生成一个形参列表完全相同的构造函数。
    using A::A; //继承A的构造函数.
    void func() override{
        std::cout << "I am C." << m_str << " " << m_i << " m_j is " << m_j << '\n';
    }

private:
    int m_j=10;
};

int main(){
    std::vector<A> vec1;
    vec1.emplace_back(A{21, " AAA "});
    vec1.emplace_back(B{22, " BBB "});
    vec1.emplace_back(C{23, " CCC "});

    for (auto& var : vec1){
        var.func();
    }

    std::vector<std::shared_ptr<A>> vec2;
    vec2.emplace_back(std::make_shared<A>(31, " AAAA "));
    vec2.emplace_back(std::make_shared<B>(32, " BBBB "));
    vec2.emplace_back(std::make_shared<C>(33, " CCCC "));
    for (const auto& var2 : vec2){
        var2->func();
    }
}
