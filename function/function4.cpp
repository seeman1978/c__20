#include <iostream>

/**
* @file
* @brief
* @details
* @author		qiangwang
* @date		    2022/3/23
* @par Copyright(c): 	2022 mega. All rights reserved.
*/
// return void function
template<typename F>
constexpr auto stars(const std::string& mine, const F& func) {
    return [func, &mine](auto&&... args) {
        std::cout << "1*******" << mine << std::endl;
        func(std::forward<decltype(args)>(args)...);
        std::cout << "\n2*******" << mine << std::endl;
    };
}

template<typename F>
constexpr auto output(const F& func) {
    return [func](auto&&... args) {
        return func(std::forward<decltype(args)>(args)...);
    };
}

template<typename F>
constexpr auto output2(const std::string& mine, const F& func) {
    return [func, &mine](auto&&... args) -> decltype(func(std::forward<decltype(args)>(args)...)){
        using R = decltype(func(std::forward<decltype(args)>(args)...));
        std::string sss = mine;
        R result = func(std::forward<decltype(args)>(args)...);
        std::cout << result << '\n';
        return result;
    };
}

template<typename F>
constexpr auto output3(const std::string& mine, const F& func) {
    return [func, &mine](auto&&... args){
        std::string sss = mine;
        int result = func(std::forward<decltype(args)>(args)...);
        std::cout << result << '\n';
        return result;
    };
}

void hello_impl() {
    std::cout << "hello, world!";
}

void hello_impl11(int i) {
    std::cout << "hello, world!" << i;
}

int hello_impl1(int i) {
    std::cout << "hello, world!" << i << '\n';
    return i;
}

std::string hello_impl2(const std::string& str, int i) {
    std::cout << str << "hello, world!" << i << '\n';
    return str;
}

int main(){
    int i = 9;
    stars("a", hello_impl)();
    stars("b", hello_impl11)(12);
    int a = output(hello_impl1)(6);
    std::cout << a << '\n';

    std::string s = output(hello_impl2)("wq", 222);
    std::cout << s << '\n';

    auto integer1 = output2("wq5", hello_impl1)(111);
    auto str1 = output2("wq6", hello_impl2)("out", 111);
    auto integer2 = output3("wq7", hello_impl1)(888);
    //auto str2 = output3("wq6", hello_impl2)("out", 111);  // error: No viable conversion from 'std::basic_string<char>' to 'int'
}