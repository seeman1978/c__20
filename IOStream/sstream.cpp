//
// Created by 王强 on 2020/11/3.
//
#include <iostream>
#include <sstream>

int main(){
    std::ostringstream s1;
    std::streamsize sz = s1.rdbuf()->sputn("This is a test", 19);   //长度超出了字符串常量的长度，将会导致循环
    s1 << '\n';
    std::cout << "The call to sputn() returned " << sz << '\n'
            << "The output sequence contains " << s1.str();

    std::istringstream s2;
    sz = s2.rdbuf()->sputn("This is a test", 14);
    std::cout << "The call to sputn() on an input stream returned " << sz << '\n';
}