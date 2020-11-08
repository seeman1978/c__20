//
// Created by 王强 on 2020/11/6.
//
#include <iostream>
#include <codecvt>
#include <vector>
#include <locale>

int main(){
    using namespace std;
    {
        locale loc1{"zh_CN.UTF-8"};
        locale loc2 {locale::global(loc1)}; //loc2为旧的全局locale；把全局locale设置为loc1。
        cout << "The name of the previous locale is: " << loc2.name( )
             << "." << endl;
        cout << "The name of the current locale is: " << loc1.name( )
             << "." << endl;
        cout << "中文\n";

        //setlocale(LC_ALL, "sv_SE.UTF-8");      //// 用这句 GCC 和 VC编译器都支持输出宽字节
        vector<std::wstring> v = {L"ar", L"zebra", L"\u00f6grupp", L"Zebra", L"\u00e4ngel",
                                       L"\u00e5r", L"f\u00f6rnamn"};
        wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
        for (const auto& s : v) {
            cout << converter.to_bytes(s) << ' ';   //unicode to ansi
        }
    }
}