//
// Created by 王强 on 2020/12/31.
//

#include <string>
#include <iostream>
//并没有使用copy on write技术
int main(){
    using namespace std;
    string str1{"hello"};
    string str2 = str1;

    cout << str1 << str2 << '\n';
}