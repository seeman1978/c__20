//
// Created by zhaoyue on 2020/11/6.
//

#include <iostream>
#include <vector>
#include <codecvt>

//do not mix std::cout and std::wcout.
//first you need to install Swedish on region and language on OS

int main(){
    using namespace std;
    {
        setlocale(LC_ALL, "sv_SE.UTF-8");      //// 用这句 GCC 和 VC编译器都支持输出宽字节,macos下不起作用(macos中不会影响wcout的locale，wcout会没有输出）
        std::wcout.imbue(std::locale("sv_SE.UTF-8"));  //// 为何这句话不起作用 in GCC（wcout会没有输出）? 为何这句只支持VC,clang(macos)
        wcout << L"中文\n";

        vector<std::wstring> v = {L"ar", L"zebra", L"\x00f6grupp", L"Zebra", L"\x00e4ngel",
                                  L"\x00e5r", L"f\x00f6rnamn"};

        for (const auto& s : v) {
            wcout << s << ' ';
        }
    }

    {
        setlocale(LC_ALL, "sv_SE.UTF-8");      //// 用这句 GCC 和 VC编译器都支持输出宽字节,macos下不起作用
        std::wcout.imbue(std::locale("sv_SE.UTF-8"));  //// 为何这句话不起作用 in GCC? 为何这句只支持VC,clang(macos)
        wcout << L"中文\n";

        vector<std::wstring> v = {L"ar", L"zebra", L"\u00f6grupp", L"Zebra", L"\u00e4ngel",
                                  L"\u00e5r", L"f\u00f6rnamn"};

        for (const auto& s : v) {
            wcout << s << ' ';
        }
    }
}