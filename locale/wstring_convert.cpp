//
// Created by 王强 on 2021/1/20.
//

#include <string>
#include <locale>
#include <codecvt>
#include <iostream>

std::wstring utf8_to_wstring(const std::string& str){
    std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
    return myconv.from_bytes(str);
}

std::string wstring_to_utf8(const std::wstring& str){
    std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
    return myconv.to_bytes(str);
}

int main(){
    try {
        std::string s = "nj: ä + \u20AC 1. 中文"; //20AC是€的unicode编码
        std::cout << s << std::endl;
        std::wstring ws = utf8_to_wstring(s);
        //用 wcout 输出 str 时, wcout 首先调用 wcstombs() (即根据当前 local 转换, 如果没有设置local,则是经典的C local, 不认识中文)把 str 的内容转换后
        //交给控制台,结果自然什么都不显示.
        std::wcout.imbue(std::locale("cs_CZ.utf-8"));
        std::wcout << ws << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << "Exception : " << e.what() << '\n';
        return EXIT_FAILURE;
    }
}