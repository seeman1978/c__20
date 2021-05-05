//
// Created by wq on 2021/5/5.
//

#include <c++/v1/iostream>

template<typename Lhs, typename Rhs>
auto Add(const Lhs& lhs, const Rhs& rhs) -> decltype(lhs + rhs)
{
    return lhs + rhs;
}

template<typename Lhs, typename Rhs>
auto Add2(const Lhs& lhs, const Rhs& rhs)
{
    return lhs + rhs;
}

int main(){
    std::cout << Add(2, 3.9) << '\n';
    std::cout << Add2(2, 3.9) << '\n';
}