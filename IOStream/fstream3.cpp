/**
* @file
* @brief
* @details
* @author		qiangwang
* @date		    2022/4/15
* @par Copyright(c): 	2022 mega. All rights reserved.
*/

#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename = "test.bin";
    std::fstream s(filename, s.binary | s.trunc | s.in | s.out);
    if (!s.is_open()) {
        std::cout << "failed to open " << filename << '\n';
    } else {
        // write
        int d = 10;
        s.write(reinterpret_cast<char*>(&d), sizeof d); // binary output
        s << 123 << "abc";                              // text output

        // for fstream, this moves the file position pointer (both put and get)
        s.seekp(0);

        // read
        s.read(reinterpret_cast<char*>(&d), sizeof d); // binary input
        int n;
        std::string str;
        if (s >> n >> str)                             // text input
            std::cout << "read back from file: " << d << ' ' << n << ' ' << str << '\n';
    }
}
