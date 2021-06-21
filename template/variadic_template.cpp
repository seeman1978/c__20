//
// Created by 王强 on 2021/6/21.
// 变长模版 ： 由模版参数包和函数参数包，两部分组成
#include <iostream>
template <typename ... Elements>
class MyTuple;
template<typename Head, typename ... Tail>
class MyTuple<Head, Tail... >:private MyTuple<Tail... >{
    Head head;
};
template<> class MyTuple<>{};

// 非类型模版
template<long... nums>
struct Multiply;

template<long first, long... last>
struct Multiply<first, last...>{
    static const long val = first * Multiply<last... >::val;
};

template<>
struct Multiply<>{
    static const long val = 1;
};

// 类型模版

template<typename I, template<typename> class... B>
struct Container{};

template<typename ... nums>
struct MultiplyT;

template<typename first, typename ... last>
struct MultiplyT<first, last...>{
    static const first val = MultiplyT<first>::value * MultiplyT<last... >::val;
};


template<typename I>
struct MultiplyT<I>{
    static const I val = 1;
};

int main(){
    std::cout << Multiply<2, 3, 4, 5>::val << '\n';
    std::cout << MultiplyT<22, 44, 66, 88, 9>::val << '\n';
}