#include <tuple>
#include <iostream>

//
// Created by qiangwang on 2021/8/5.
//
template <typename... T>
void foo(int a, std::tuple<T...> TupleTest){
    auto [ gpa2, name2, grade2  ] = TupleTest;
    std::cout << "a is " << a << '\n';
    std::cout << "gpa2 is " << gpa2 << '\n';
    std::cout << "name is " << name2 << '\n';
    std::cout << "grade2 is " << grade2 << '\n';
};

int main(){
    // make_tuple so we don't need to enter all the type names
    foo(0, std::make_tuple(2, "TEST", 5.5));
}