//
// Created by 王强 on 2021/1/14.
//

#include <iostream>
struct Fraction{
    int m_numerator;
    int m_denominator;
};

template<class charT, class traits>
inline
std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits>& strm, Fraction& f){
    int n, d;
    strm >> n;
    if (strm.peek() == '/'){
        strm.ignore();
        strm >> d;
    }
    else {
        d = 1;
    }

    if (d == 0){
        strm.setstate(std::ios::failbit);
        return strm;
    }

    if (strm){
        f = Fraction{n, d};
    }
    return strm;
}

int main(){
    Fraction f;
    std::cin >> f;
    if (std::cin.good()){
        std::cout << '\n';
        std::cout << f.m_numerator << '/' << f.m_denominator;
    }
    else
    {
        std::cout << "input is error.";
    }
}