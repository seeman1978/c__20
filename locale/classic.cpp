//
// Created by zhaoyue on 2020/11/6.
//

#include <locale>
#include <iostream>

int main(){
    using namespace std;
    {
        std::cout << "中文\n";
        std::wcout << L"中文\n";
        locale loc1{"zh_CN"};
        locale loc2 {locale::global(loc1)}; //loc2为旧的全局locale；把全局locale设置为loc1。
        cout << "The name of the previous locale is: " << loc2.name( )
             << "." << endl;
        cout << "The name of the current locale is: " << loc1.name( )
             << "." << endl;
        std::wcout << L"中文\n";
    }
}