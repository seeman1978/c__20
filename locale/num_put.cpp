//
// Created by 王强 on 2020/11/8.
//
#include <iostream>

int main(){
    double d = 1234567.89;
    std::cout.imbue(std::locale("de_DE"));
    std::cout << "Direct conversion to string : \n"
        << std::to_string(d) << '\n'
        << "Output using a german locale:\n"
        << std::fixed << d << '\n'
        << "Output using an american locale:\n";
    std::cout.imbue(std::locale("en_US.UTF-8"));
    auto& f = std::use_facet<std::num_put<char>>(std::cout.getloc());
    f.put(std::ostreambuf_iterator<char>(std::cout), std::cout, ' ', d);
    std::cout << '\n';
}