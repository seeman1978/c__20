//
// Created by wq on 2020/11/8.
//

#include <ctime>
#include <locale>
#include <codecvt>
#include <iostream>
#include <iomanip>
int main(){
    setlocale(LC_ALL, "ja_JP.utf8");      //// 用这句 GCC 和 VC编译器都支持输出宽字节

    std::time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);
    std::wcout.imbue(std::locale("ru_RU.utf8"));
    std::wcout << L"ru_RU: " << std::put_time(&tm, L"%c %Z") << '\n';
    std::wcout.imbue(std::locale("ja_JP.utf8"));
    std::wcout << L"ja_JP: " << std::put_time(&tm, L"%c %Z") << '\n';
    std::wcout << L"ja_JP: " << std::put_time(std::localtime(&t), L"%A %c") << '\n';

    //下面这段代码为何不生效，还不清楚
    std::wbuffer_convert<std::codecvt_utf8<wchar_t>> conv(std::cout.rdbuf());
    std::wostream out(&conv);
    out.imbue(std::locale("ja_JP.utf8"));
    // this I/O manipulator std::put_time uses std::time_put<wchar_t>
    out << std::put_time(std::localtime(&t), L"%A %c") << '\n';
}