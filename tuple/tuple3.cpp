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

int main(){
    int i = 9;
    handle(std::tuple_cat(std::make_tuple(1, "hellow"), std::forward_as_tuple(i)));
    std::cout << "i is " << i << '\n';
}