//
// Created by zhaoyue on 2020/11/6.
//
#include <iostream>
#include <locale>

int main()
{
    {
        std::wcout << "User-preferred locale setting is " << std::locale().name().c_str() << '\n';
        // on startup, the global locale is the "C" locale
        std::wcout << 1000.01 << '\n';
        // replace the C++ global locale as well as the C locale with the user-preferred locale
        std::locale::global(std::locale("zh_CN.UTF-8"));    //linux,macos不起作用
        std::wcout << 1000.01 << '\n';
        // use the new global locale for future wide character output
        std::wcout.imbue(std::locale("zh_CN.UTF-8"));
        // output the same number again
        std::wcout << 1000.01 << '\n';
    }

}
