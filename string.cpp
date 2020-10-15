//
// Created by zhaoyue on 2020/9/4.
//

#include <string>
#include <iostream>

template<typename T>
void print(const T& var){
    for (const auto& a : var){
        std::cout << a << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::wstring s1 = L"hello";
    std::string s2 = R"(aa)";
    std::string s3 = "aa";

    const char8_t *utf8 = u8"你好";
    const char16_t *utf16 = u"你好";
    const char32_t *utf32 = U"你好";

    std::u8string str8 = u8"你好";
    std::u16string str16 = u"你好";
    std::u32string str32 = U"你好";

    setlocale(LC_ALL, ".utf8");
    print(str8);
    print(str16);
    print(str32);
    //std::cout << str8 << std::endl;

    //std::cout << str16 << std::endl;
    //std::cout << str32 << std::endl;
}