//
// Created by 王强 on 2020/11/6.
//

//
// Created by 王强 on 2020/11/6.
//
#include <iostream>
#include <codecvt>
#include <vector>
int main(){
    using namespace std;
    {
        wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;

        //setlocale(LC_ALL, "sv_SE.UTF-8");      //// 用这句 linux 和 windows编译器都支持输出宽字节
        vector<std::wstring> v = {L"ar", L"zebra", L"\u00f6grupp", L"Zebra", L"\u00e4ngel",
                                  L"\u00e5r", L"f\u00f6rnamn"};
        vector<std::string> ansi_v;

        wcout.imbue(std::locale("sv_SE.UTF-8"));
        for (const auto& s : v){
            wcout << s << L' ';
            ansi_v.emplace_back(converter.to_bytes(s));
        }
        wcout << '\n';

        for (const auto& s : ansi_v){
            wcout << converter.from_bytes(s) << L' ';
        }
    }
}