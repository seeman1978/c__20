//
// Created by 王强 on 2021/1/4.
//

#include <regex>
#include <iostream>

int main(){
    using namespace std;
    {
        string data = "Xml tag: <tag-name>the value</tag-name>.";
        cout << "data: " << data << '\n';
        smatch m;   //for returned details of the match
        regex reg{R"(<(.*)>(.*)</(\1)>)"};
        bool found = regex_search(data, m, reg);
        cout << "m.empty(): " << boolalpha << m.empty() << '\n';
        cout << "m.size(): " << m.size() << '\n';
        if (found){
            cout << "m.str(): " << m.str() << '\n';
            cout << "m.length(): " << m.length() << '\n';
            cout << "m.position(): " << m.position() << '\n';
            cout << "m.prefix(): " << m.prefix().str() << '\n';
            cout << "m.suffix(): " << m.suffix().str() << '\n';
            int i = 0;
            for (auto var : m){
                cout << "str(): " << var.str() << '\n';
                cout << "position:" << m.position(i++) << '\n';
                cout << "length: " << var.length() << '\n';
            }
        }
    }
}