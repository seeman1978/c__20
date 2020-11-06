//
// Created by zhaoyue on 2020/11/5.
//

//do not mix std::cout and std::wcout.
//first you need to install Swedish on region and language on OS
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::setlocale(LC_ALL, "sv_SE.UTF-8");      //// 用这句 GCC 和 VC编译器都支持输出宽字节
    //std::wcout.imbue(std::locale("sv_SE.UTF-8"));  //// 为何这句话不起作用 in GCC? 为何这句只支持VC
    std::wcout << L"LC_ALL: " << std::setlocale(LC_ALL, nullptr) << std::endl;
    std::wcout << L"LC_CTYPE: " << std::setlocale(LC_CTYPE, nullptr) << std::endl;

    std::vector<std::wstring> v = {L"ar", L"zebra", L"\u00f6grupp", L"Zebra", L"\u00e4ngel",
                                   L"\u00e5r", L"f\u00f6rnamn"};

    std::wcout << "Swedish locale collation order: ";
    std::sort(v.begin(), v.end(), std::locale("sv_SE.UTF-8"));
    for (const auto& s : v) {
        std::wcout << s << ' ';
    }
    std::wcout << '\n';

    std::wcout << "Default locale collation order: ";
    std::sort(v.begin(), v.end());
    for (const auto& s : v){
        std::wcout << s << ' ';
    }
    std::wcout << '\n';

    std::wcout << "English locale collation order: ";
    std::sort(v.begin(), v.end(), std::locale("en_US.UTF-8"));
    for (const auto &s : v) {
        std::wcout << s << ' ';
    }
    std::wcout << '\n';
}
