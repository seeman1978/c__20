//
// Created by wq on 2021/2/16.
//

#include <iostream>

int main(){

    std::cout << "\1151\n";

    std::wcout.imbue(std::locale("sv_SE.UTF-8"));
    std::wcout << L"\x00e5" << std::endl;
    std::wcout << L"\x00e51" << std::endl;
    std::wcout << L"\u00e5" << std::endl;
    const char8_t *mbstr = u8"\u00e5";
    std::string str {reinterpret_cast<const char *>(mbstr)};
    std::cout << str << '\n';
}