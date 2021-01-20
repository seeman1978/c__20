//
// Created by 王强 on 2021/1/19.
//

#include <locale>
#include <iostream>
#include <vector>

void try_widen(const std::ctype<wchar_t>& f, char c)
{
    wchar_t w = f.widen(c);
    std::cout << "The single-byte character " << +(unsigned char)c
              << " widens to " << +w << '\n';
}

void try_widen2(const std::ctype<wchar_t>& f, char* c)
{
    wchar_t str2 [16];
    bool result = f.widen(c, c+strlen(c), &str2[0]) != 0;
    str2[strlen(c)] = '\0';
    std::cout << "The single-byte character ";
    for (int i=0; i<strlen(c); ++i){
        std::cout << +(unsigned char)*(c+i);
    }

    std::cout << " widens to ";
    for (int i=0; i<strlen(c); ++i){
        std::cout << +(str2[i]);
    }
    std::cout << '\n';
}

int main()
{
    {
        //std::locale::global(std::locale("cs_CZ.iso88592")); //捷克语,linux和windows
        std::locale::global(std::locale("cs_CZ.iso8859-2")); //捷克语，macos
        auto& f = std::use_facet<std::ctype<wchar_t>>(std::locale());
        std::cout << std::hex << std::showbase << "In Czech ISO-8859-2 locale:\n";
        try_widen(f, 'a');
        try_widen(f, '\xdf'); // German letter ß (U+00df) in ISO-8859-2
        try_widen(f, '\xec'); // Czech letter ě (U+011b) in ISO-8859-2

        //std::locale::global(std::locale("cs_CZ.utf8"));   //linux和windows
        std::locale::global(std::locale("cs_CZ.utf-8"));    //macos
        auto& f2 = std::use_facet<std::ctype<wchar_t>>(std::locale());
        std::cout << "In Czech UTF-8 locale:\n";
        try_widen2(f2, "a");

        try_widen2(f2, "\xF9\xC3");
        try_widen2(f2, "\xec");
    }

    {
        using namespace std;
        locale loc1 ("en_US.UTF-8");
        char *str1 = "Hello everyone!";
        wchar_t str2 [16];
        bool result1 = (use_facet<ctype<wchar_t> > ( loc1 ).widen
                ( str1, str1 + strlen(str1), &str2[0] ) != 0);  // C4996
        str2[strlen(str1)] = '\0';
        cout << str1 << endl;
        wcout << &str2[0] << endl;

        ctype<wchar_t>::char_type charT;
        charT = use_facet<ctype<char> > ( loc1 ).widen( 'a' );
    }
}