//
// Created by 王强 on 2021/1/5.
//
#include <regex>
#include <iostream>

int main(){
    using namespace std;
    {
        string data = "<person>\n<first>Nico</first>\n<last>Josuttis</last>\n</person>\n";
        regex reg{R"(<(.*)>(.*)</(\1)>)"};
        sregex_token_iterator pos(data.cbegin(), data.cend(), reg, {0, 2});
        sregex_token_iterator end;
        for (; pos != end; ++pos){
            cout << "match: " << pos->str() <<endl;
        }
    }

    {
        string names = "nice , jim, helmut, paul, tim, john paul, rita";
        regex reg{R"([ \t\n]*[,;.][ \t\n]*)"};
        sregex_token_iterator pos(names.cbegin(), names.cend(), reg, -1);
        sregex_token_iterator end;
        for ( ; pos != end; ++pos){
            cout << "name: " << *pos << '\n';
            cout << "length: " << pos->length() << '\n';
        }
    }

}
