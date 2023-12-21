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

int32_t func(int32_t i){
    return i;
}

int main(){
    std::cout << exec_decorator("hello1", func)(5) << '\n';
    std::cout << exec_decorator("hello2", func)(9) << '\n';
}