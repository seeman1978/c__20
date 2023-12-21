//
// Created by wq on 23-12-21.
//

#include <string>
#include <iostream>

template<typename F>
auto exec_decorator(const std::string& str_trace, const F& func) noexcept {
    return [=](auto&&... args) noexcept {
        std::cout << "begin to invoke a method. trace is " << str_trace << "\n";
        auto result = func(std::forward<decltype(args)>(args)...);
        std::cout << "end to invoke a method\n";
        return result;  // succeed
    };
}

template<typename F>
auto exec_decorator(const std::string& str_trace, const F& func) noexcept {
    return [=](auto&&... args) noexcept {
        std::cout << "begin to invoke a method. trace is " << str_trace << "\n";
        func(std::forward<decltype(args)>(args)...);
        std::cout << "end to invoke a method\n";
    };
}

int32_t func1(int32_t i){
    return i;
}

void func2(const std::string &str){
    std::cout << str + " world \n";
}

int main(){
    std::cout << exec_decorator("hello1", func1)(5) << '\n';
    std::cout << exec_decorator("hello2", func1)(9) << '\n';
    exec_decorator("hello3", func2)("hello");
}