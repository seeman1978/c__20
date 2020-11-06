//
// Created by zhaoyue on 2020/11/6.
//

#include <locale>
#include <iostream>

int main(){
    std::locale loc(std::locale(), new std::ctype<char>);
    std::cout << "The default locale is " << std::locale().name() << '\n'
        << "The user's locale is " << std::locale("").name() << '\n'
        << "A nameless locale is " << loc.name() << '\n';
}