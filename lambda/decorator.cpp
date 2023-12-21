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

int32_t func(int32_t i){
    return i;
}

int main(){
    std::cout << exec_decorator("hello1", func)(5) << '\n';
    std::cout << exec_decorator("hello2", func)(9) << '\n';
}