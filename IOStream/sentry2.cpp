//
// Created by 王强 on 2021/1/6.
//

#include <iostream>
#include <sstream>

struct Foo{
    std::string str;
};

std::istream& operator>>(std::istream& is, Foo& f){
    std::istream::sentry s{is};
    if (s){
        char ch[6];
        is.read(ch, 5);
        f.str = ch;
    }
    return is;
}

int main(){
    using namespace std;
    string input{"   abcde"};
    istringstream stream{input};
    Foo f;
    stream >> f;
    cout << f.str << "\n";
}
