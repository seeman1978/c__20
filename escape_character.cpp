//
// Created by wq on 2021/2/16.
//

#include <iostream>

int main(){
    //注意，如果反斜线\后面跟着的八进制数字超过3个，只有前3个数字与\构成转义序列。
    std::cout << "\1151\n"; //输出M1

    //相反，\x要用到后面跟着的所有数字，表示一个字符，例如，"\x1234"表示一个16位的字符，
    std::wcout.imbue(std::locale("sv_SE.UTF-8"));
    std::wcout << L"\x00e5" << std::endl;
    std::wcout << L"\x00e51" << std::endl;
    std::wcout << L"\u00e5" << std::endl;
    const char8_t *mbstr = u8"\u00e5";
    std::string str {reinterpret_cast<const char *>(mbstr)};
    std::cout << str << '\n';
}