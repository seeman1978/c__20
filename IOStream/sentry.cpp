//
// Created by 王强 on 2020/11/8.
//

#include <string>
#include <iostream>

struct Foo{
    std::string str;
};

std::ostream& operator<<(std::ostream& os, const Foo& f){
    std::ostream::sentry s(os);
    if (s){
        os << f.str;
    }
    return os;
}

int main(){
    Foo f{"  abcde"};
    std::cout << f << '\n';
}