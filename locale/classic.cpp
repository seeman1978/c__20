//
// Created by zhaoyue on 2020/11/6.
//

#include <locale>
#include <iostream>
#include <vector>

//do not mix std::cout and std::wcout.
//first you need to install Swedish on region and language on OS

int main(){
    using namespace std;
    {
        locale loc1{"zh_CN.UTF8"};
        locale loc2 {locale::global(loc1)}; //loc2为旧的全局locale；把全局locale设置为loc1。
        cout << "The name of the previous locale is: " << loc2.name( )
             << "." << endl;
        cout << "The name of the current locale is: " << loc1.name( )
             << "." << endl;
        std::cout << "中文\n";

        std::setlocale(LC_ALL, "sv_SE.UTF-8");      //// 用这句 GCC 和 VC编译器都支持输出宽字节
        std::vector<std::wstring> v = {L"ar", L"zebra", L"\u00f6grupp", L"Zebra", L"\u00e4ngel",
                                       L"\u00e5r", L"f\u00f6rnamn"};

    }
}