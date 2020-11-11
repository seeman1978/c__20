//
// Created by wq on 2020/11/6.
//

#include <iostream>

template<typename T>
void try_compare(const std::locale& l, const T* p1, const T* p2){
    auto& f = std::use_facet<std::collate<T>>(l);
    std::basic_string<T> s1(p1), s2(p2);
    if (f.compare(&s1[0], &s1[0]+s1.size(), &s2[0], &s2[0]+s2.size()) < 0){
        std::wcout << p1 << " before " << p2 << '\n';
    }
    else{
        std::wcout << p2 << " before " << p1 << '\n';
    }
}

int main(){
    std::locale::global(std::locale("en_US.utf-8"));
    std::wcout.imbue(std::locale("sv_SE.utf-8"));
    std::wcout << "In the American locale: ";
    try_compare(std::locale(), "hrnec", "chrt");
    std::wcout << "In the Czech locale: ";
    try_compare(std::locale("cs_CZ.utf-8"), "hrnec", "chrt");

    std::wcout << "In the American locale: ";
    try_compare(std::locale(), L"år", L"ängel");
    std::wcout << "In the Swedish locale: ";
    try_compare(std::locale("sv_SE.utf-8"), L"år", L"ängel");
}