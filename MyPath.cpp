//
// Created by 王强 on 2020/3/4.
//

#include <filesystem>
#include <iostream>
int main() {
    std::filesystem::path mypath("/Users/wangqiang/Downloads/2020第8周应用软件部居家研发工作计划与日报.xlsx");
    std::cout << "p1 = " << mypath << '\n';
    //std::cout << u8"中文" << std::endl;
    mypath.make_preferred();    //为何没起作用？
    std::cout << "p1 = " << mypath << '\n';

    mypath.remove_filename();
    std::cout << "p1 = " << mypath << '\n' << "has file name " << mypath.has_filename() << std::endl;

    mypath.clear();
    std::cout << mypath.empty() << std::endl;
}