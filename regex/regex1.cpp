//
// Created by 王强 on 2021/1/4.
//

#include <regex>
#include <iostream>

void out(bool b){
    std::cout << (b ? "found" : "not found") << '\n';
}

int main(){
    using namespace std;
    {
        regex reg1{R"(<.*>.*</.*>)"};   //这个正则表达式写的并不好，鸟用没有
        bool found = regex_match("<tag>value</tag>", reg1);
        out(found); //found

        found = regex_match("<tag>value/>", reg1);
        out(found); //found
    }

    {
        //find xml tagged value(tags before and after the value must match)
        regex reg2{R"(<(.*)>.*</\1>)"}; //利用了group概念
        bool found = regex_match("<tag>value</tag>", reg2);
        out(found); //found

        found = regex_match("<tag>value</Tag>", reg2);
        out(found); //not found
    }

    {//UNIX grep 语法
        regex reg3{R"(<\(.*\)>.*</\1>)", regex_constants::grep};
        bool found = regex_match("<tag>value</tag>", reg3);
        out(found);

        found = regex_match("<Tag>value</tag>", reg3);
        out(found);
    }
    {//regex_match versus regex_search
        regex reg4{R"(<(.*)>.*</\1>)"};
        bool found = regex_match("xml tag:<tag>value</tag>", reg4);
        out(found);  //not found
        found = regex_search("xml tag:<tag>value</tag>", reg4);
        out(found); //found
    }
}