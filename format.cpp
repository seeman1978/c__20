//
// Created by wq on 2020/5/28.
//

#include <iostream>
#include <format>

int main()
{
    std::format("{} {}!", "Hello", "world", "something");   // OK ：产生 "Hello world!"
}