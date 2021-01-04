//
// Created by wq on 2021/1/4.
//

//
// Created by wq on 2021/1/4.
//

#include <regex>
#include <iostream>

int main(){
    using namespace std;
    string data = "<person>\n<first>Nico</first>\n<last>Josuttis</last>\n</person>\n";
    cout << "data: " << data << '\n';
    smatch m;
    regex reg{R"(<(.*)>(.*)</(\1)>)"};  //.*表示不包括换行符的任意字符。
    auto pos = data.cbegin();
    auto end = data.cend();
    for (;  regex_search(pos, end, m, reg) ; pos=m.suffix().first) {
        cout << "match: " << m.str() << '\n';
        cout << "tag: " << m.str(1) << '\n';
        cout << "value: " << m.str(2) << '\n';
    }


}