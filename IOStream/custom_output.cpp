//
// Created by 王强 on 2021/1/13.
//

#include <ostream>
#include <iostream>
#include <vector>

template<typename T1, typename T2>
struct S{
    std::pair<T1, T2> m_pair;
};

template<typename T1, typename T2>
std::ostream& operator << (std::ostream& strm, const std::pair<T1, T2>& p){
    return strm << "[" << p.first << "," << p.second << "]";
}

std::ostream& operator << (std::ostream& strm, const S<int, long>& p){
    return strm << "[" << p.m_pair.first << "," << p.m_pair.second << "]";
}

int main(){
    std::pair<int, long> p(42, 77777);
    std::cout << p << std::endl;

    std::vector<std::pair<int, long>> v{std::make_pair(1, 1111), std::make_pair(2, 2222)};
    //下面这句话无法编译，why？
    //https://en.cppreference.com/w/cpp/language/adl
    //里面有关于ADL的详细介绍，augument dependent lookup
    //std::copy(v.begin(), v.end(), std::ostream_iterator<std::pair<int, long>>(std::cout, "\n"));

    //https://en.cppreference.com/w/cpp/language/dependent_name#Lookup_rules
    //只有当数据类型不是内置类型（用户定义类型），或者不是vector和pair才可以。
    std::vector<S<int, long>> v2{S<int, long>{std::make_pair(1, 1111)}, S<int, long>{std::make_pair(2, 2222)}};
    std::copy(v2.begin(), v2.end(), std::ostream_iterator<S<int, long>>(std::cout, "\n"));
}