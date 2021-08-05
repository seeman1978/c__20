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
}
template <typename... T>
void foo2(std::tuple<T...> TupleTest){
    auto [ gpa2, name2, grade2  ] = TupleTest;

    std::cout << "gpa2 is " << gpa2 << '\n';
    std::cout << "name is " << name2 << '\n';
    std::cout << "grade2 is " << grade2 << '\n';

    grade2 = 100.5;
}

int main(){
    // make_tuple so we don't need to enter all the type names
    foo(0, std::make_tuple(2, "TEST", 5.5));

    int i = 9;
    std::string name="wangqiang";
    double score = 98.5;
    foo2(std::forward_as_tuple(i, name, score));
    std::cout << "gpa2 is " << i << '\n';
    std::cout << "name is " << name << '\n';
    std::cout << "grade2 is " << score << '\n';
}