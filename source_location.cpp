//
// Created by zhaoyue on 2020/8/12.
//

#include <iostream>
#include <string_view>
#include <source_location>

void log(std::string_view message, const std::source_location& location = std::source_location::current())
{
    std::cout << "info:"
        << location.file_name() << ':'
        << location.line() << ' '
        << message << '\n';
}

int main()
{
    log("Hello World!");
}