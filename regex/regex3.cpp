//
// Created by wq on 2021/1/4.
//

#include <regex>
#include <iostream>

int main(){
    using namespace std;
    string data = "xml tag: <tag-name>the value</tag-name>.";
    cout << "data: " << data << '\n';
    smatch m;
    regex reg{R"(<(.*)>(.*)</(\1)>)"};
    bool found = regex_search(data, m, reg);
    if (found){
        int i = 0;
        for(auto var : m){
            cout << "str:" << var.str() << '\n';
            cout << "length:" << var.length() << '\n';
            cout << "position:" << m.position(i++) << '\n';
            cout << "first:" << *var.first << '\n';     //第一个元素
            cout << "second:" << *var.second << '\n';   //最后一个元素的下一个位置
        }
    }
}