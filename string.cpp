//
// Created by zhaoyue on 2020/9/4.
//

#include <string>

int main()
{
    std::wstring s1 = L"hello";
    std::string s2 = R"(aa)";
    std::string s3 = "aa";
    std::string utf8 = u8"你好";
    std::string utf16 = u"你好";
    std::string utf32 = U"你好";
}