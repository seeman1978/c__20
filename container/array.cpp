//
// Created by zhaoyue on 2020/11/23.
//

#include <array>

#include <iostream>

int main(){

    std::array<std::string, 5> a {"hello", "nice", "how", "are", "you"};
    std::cout << std::tuple_size<decltype(a)>::value << '\n';
    using T = std::tuple_element<1, decltype(a)>::type;

    std::cout << std::boolalpha;
    std::cout << std::is_same<T, std::string>::value << '\n';

    const auto const_data = a;
    using CT = std::tuple_element<0, decltype(const_data)>::type;

    std::cout << std::is_same<T, CT>::value << '\n';
    std::cout << std::is_same<CT, const std::string>::value << '\n';
}