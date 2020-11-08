//
// Created by wq on 2020/11/8.
//
#include <iostream>
#include <locale>
#include <sstream>
#include <iomanip>

//note: choose clang to observe the output. libstdc++ does not correctly implement the %b specifier: bug 78714
int main(){
    std::tm t{};
    std::istringstream ss("2011-Februar-18 23:12:34");
    ss.imbue(std::locale("de_DE.utf-8"));
    ss >> std::get_time(&t, "%Y-%b-%d %H:%M:%S");
    if (ss.fail()){
        std::cout << "Parse failed\n";
    }
    else{
        std::cout << std::put_time(&t, "%c") << '\n';
    }
}
