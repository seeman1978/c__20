//
// Created by 王强 on 2020/3/5.
//

#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;
int main()
{
    fs::space_info devi = fs::space("/dev/null");
    fs::space_info tmpi = fs::space("/tmp");

    std::cout << ".        Capacity       Free      Available\n"
              << "/dev:   " << devi.capacity << "   "
              << devi.free << "   " << devi.available  << '\n'
              << "/tmp: " << tmpi.capacity << " "
              << tmpi.free << " " << tmpi.available  << '\n';
}