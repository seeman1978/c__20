//
// Created by wq on 2021/1/4.
//

#include <regex>
#include <iostream>

int main(){
    using namespace std;
    string data = "<person><first>Nico</first><last>Josuttis</last></person>";
    cout << "data: " << data << '\n';

    regex reg{R"(<(.*)>([^>]*)</(\1)>)"};  //.*表示不包括换行符的任意字符。

    sregex_iterator pos{data.cbegin(), data.cend(), reg};
    sregex_iterator end;    //default构造函数给出末尾的下一位置，就是结束的位置

    for (;  pos!=end; ++pos) {
        cout << "match: " << pos->str() << '\n';
        cout << "tag: " << pos->str(1) << '\n';
        cout << "value: " << pos->str(2) << '\n';
    }

    sregex_iterator beg{data.cbegin(), data.cend(), reg};
    for_each(beg, end, [](const smatch& m){
        cout << "match: " << m.str() << '\n';
        cout << "tag: " << m.str(1) << '\n';
        cout << "value: " << m.str(2) << '\n';
        cout << "position:" << m.position() << '\n';
    });

}