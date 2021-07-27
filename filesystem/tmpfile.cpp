//
// Created by qiangwang on 2021/7/27.
//

#include <iostream>
#include <filesystem>

int main(){
    std::cout << "TMP_MAX = " << TMP_MAX << '\n'
        << "FOPEN_MAX = " << FOPEN_MAX << '\n';
    std::FILE* tmpf = std::tmpfile();
    std::fputs("Hello, world", tmpf);
    //The function is equivalent to fseek(stream, 0, SEEK_SET);
    std::rewind(tmpf);  //Moves the file position indicator to the beginning of the given file stream.
    char buf[6];
    std::fgets(buf, sizeof buf, tmpf);
    std::cout << buf << '\n';
    // Linux-specific method to display the tmpfile name
    std::cout << std::filesystem::read_symlink(
            std::filesystem::path("/proc/self/fd")/std::to_string(fileno(tmpf))) << '\n';
}