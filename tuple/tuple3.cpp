#include <tuple>
#include <iostream>

//
// Created by qiangwang on 2021/8/10.
//
template <typename... T>
void handle(std::tuple<T...> tupleParam){
    auto [ v1, v2, v3 ] = tupleParam;
    std::cout << "v1: " << v1 << " .v2: " << v2 << " . v3: " << v3 << '\n';
    v3 = 88;
}

struct st{
    std::string str;
    int i;
};
template <typename... T>
void handle2(std::tuple<T...> tupleParam){
    auto [v1] = tupleParam;
    std::cout << "i is " << v1 << '\n';
    v1 = 99;
}

template <typename... T>
void handle3(std::tuple<T...> tupleParam){
    auto v1 = std::get<0>(tupleParam);
    std::cout << "i is " << v1 << '\n';
    v1 = 33;
    std::get<0>(tupleParam) = 44;
}

template <typename... T>
void handle4(std::tuple<T...> tupleParam){
    int v1;
    std::tie(v1) = tupleParam;
    std::cout << "i is " << v1 << '\n';
    v1 = 33;
}

int main(){
    int i = 9;
    handle(std::tuple_cat(std::make_tuple(1, "hellow"), std::forward_as_tuple(i)));
    std::cout << "i is " << i << '\n';

    st st1{"hello world", 100};
    handle2(std::forward_as_tuple(st1.i));
    std::cout << "st i is " << st1.i << '\n';

    handle3(std::forward_as_tuple(st1.i));
    std::cout << "st i is " << st1.i << '\n';

    handle4(std::forward_as_tuple(st1.i));
    std::cout << "st i is " << st1.i << '\n';
}