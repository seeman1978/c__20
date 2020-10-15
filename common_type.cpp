//
// Created by zhaoyue on 2020/10/15.
//

#include <iostream>
#include <type_traits>
#include <typeinfo>

template<class T>
struct Number{
    T n;
};

template<class T, class U>
Number<typename std::common_type<T, U>::type> operator+(const Number<T>& lhs,
        const Number<U>& rhs){
    return {lhs.n+rhs.n};
}

int main(){
    Number<int> i1 {1}, i2 {2};
    Number<double> d1{2.3}, d2{3.5};
    std::cout << "i1 + i2 :" << (i1+i2).n << "\n"
        << "i1 + d2 :" <<(i1+d2).n << "\n"
        << "d1 + i2 :" << (d1+i2).n << '\n'
        << "d1 + d2 :" << (d1+d2).n << '\n';

    auto temp = i1 + d2;
    std::cout << "type of temp:" << typeid(temp).name() << std::endl;

    auto temp2 = d1 + d2;
    std::cout << "type of temp2:" << typeid(temp2).name() << std::endl;

    auto temp3 = i1 + i2;
    std::cout << "type of temp3:" << typeid(temp3).name() << std::endl;
}