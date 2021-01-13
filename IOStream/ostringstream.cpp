//
// Created by 王强 on 2021/1/13.
//

#include <iostream>
#include <sstream>
#include <bitset>

int main() {
    using namespace std;
    ostringstream os;
    os << "dec: " << 15 << hex << " hex: " << 15 << '\n';
    cout << os.str();

    // append floating value
    os << "float: " << 4.67 << '\n';
    cout << os.str();

    bitset<15> b{5789};
    os << "bitset: " << b << '\n';
    cout << os.str();

    //清除stream里面的内容
    os.str("");
    cout << "after clear: " << os.str();
}