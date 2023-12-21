//
// Created by wq on 23-12-21.
//
#include <string>
#include <iostream>

template<typename R, typename... Args>
auto exec_decorator(const std::string& str_trace, R(*func)(Args...)) noexcept {
    return [=]<typename... Args2>(Args2 &&... args) noexcept {
        std::cout << "begin to invoke a method. trace is " << str_trace << "\n";
        R result = func(std::forward<decltype(args)>(args)...);
        std::cout << "end to invoke a method\n";
        return result;  // succeed
    };
}

template<typename... Args>
auto exec_decorator(const std::string& str_trace, void(*func)(Args...)) noexcept {
    return [=]<typename... Args2>(Args2 &&... args) noexcept {
        std::cout << "begin to invoke a method. trace is " << str_trace << "\n";
        func(std::forward<decltype(args)>(args)...);
        std::cout << "end to invoke a method\n";
    };
}

int32_t func1(int32_t i){
    return i;
}

std::string func2(int32_t i){
    return "world";
}

std::string func3(const std::string &str){
    return str + " world ";
}

void func4(const std::string &str){
    std::cout << str + " world \n";
}

int main(){
    std::cout << exec_decorator("hello1", func1)(5) << '\n';
    std::cout << exec_decorator("hello2", func1)(9) << '\n';
    std::cout << exec_decorator("hello3", func2)(9) << '\n';
    std::cout << exec_decorator("hello4", func3)("hello") << '\n';
    exec_decorator("hello5", func4)("hello");
}