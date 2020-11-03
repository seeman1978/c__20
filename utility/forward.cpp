//
// Created by wq on 2020/11/1.
//

#include <iostream>
#include <utility>
#include <thread>
struct A{
    A(int&& n){
        std::cout << "rvalue overload, n=" << n << '\n';
    }
    A(int& n){
        std::cout << "lvalue overload, n=" << n << '\n';
    }
};

class B{
public:
    template<class T1, class T2, class T3> B(T1&& t1, T2&& t2, T3&& t3):
        m_a1{std::forward<T1>(t1)},
        m_a2{std::forward<T2>(t2)},
        m_a3{std::forward<T3>(t3)}{
        }
private:
    A m_a1, m_a2, m_a3;
};

template<class T, class U>
std::unique_ptr<T> make_unique1(U&& u){
    return std::unique_ptr<T>(new T(std::forward<U>(u)));
}

template<class T, class... U>
std::unique_ptr<T> make_unique2(U&&... u){
    return std::unique_ptr<T>(new T(std::forward<U>(u)...));
}

int main(){
    auto p1 = make_unique1<A>(2);
    int i = 1;
    auto p2 = make_unique1<A>(i);

    std::cout << "B\n";
    auto t = make_unique2<B>(2, i, 3);

    i = 0;
}