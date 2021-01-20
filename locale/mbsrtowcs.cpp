//
// Created by 王强 on 2021/1/20.
//

#include <iostream>
#include <vector>
#include <clocale>
#include <cwchar>

void print_as_wide(const char8_t* mbstr)
{
    const char8_t* mbstr2 = mbstr;

    std::mbstate_t state = std::mbstate_t();
    // 转化为wchar后，z：占用2个byte；ß：占用2个byte；水：占用2个byte；🍌：占用4个byte；一个10个byte
    std::size_t len = 1 + std::mbsrtowcs(nullptr, reinterpret_cast<const char **>(&mbstr), 0, &state);
    std::vector<wchar_t> wstr(len);
    std::mbsrtowcs(&wstr[0], reinterpret_cast<const char **>(&mbstr), wstr.size(), &state);
    std::wcout << "Wide string: " << &wstr[0] << '\n'
               << "The length, including '\\0': " << wstr.size() << '\n';
    //wstr的size是11
    wchar_t wstr2[len];
    std::mbsrtowcs(&wstr2[0], reinterpret_cast<const char **>(&mbstr2), 11, &state);
    std::wstring wstr3{wstr2};
    std::wcout << "Wide string: " << wstr3 << " The length, not including '\\0': " << wstr3.size() << std::endl;
}

int main()
{
    std::setlocale(LC_ALL, "en_US.utf8");
    const char8_t *mbstr = u8"z\u00df\u6c34\U0001f34c"; // or u8"zß水🍌",ß水🍌的编码是unicode编码。通过u8前缀，系统会自动把unicode编码字符转换为utf8编码字符
    //zß水🍌的utf编码为 7a c39f e6b064 f09f8d8c.
    //zß水🍌的string和wstring的长度相同，是个巧合。

    int nLength = std::char_traits<char8_t>::length(mbstr);
    std::cout << "The length of ansi char is " << nLength << '\n';
    print_as_wide(mbstr);
}