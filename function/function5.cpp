/**
* @file
* @brief
* @details
* @author		qiangwang
* @date		    2022/3/28
* @par Copyright(c): 	2022 mega. All rights reserved.
*/

#include <iostream>
#include <utility>
/*
template<typename F>
auto output(const F& func) {
    return [func](auto&&... args) {
        std::cout << func(std::forward<decltype(args)>(args)...);
    };
}
*/
float divide_impl(float a, float b) {
    return a/b;
}

template<typename R, typename... Args>
auto stars(const std::string& mine, R(*in)(Args... args)) {
    return [=](Args&&... args) {
        std::cout << "*******" << std::endl;
        std::cout << mine << std::endl;
        R result = in(std::forward<decltype(args)>(args)...);
        std::cout << "*******" << std::endl;
        return result;
    };
}

int hello_impl(int i) {
    std::cout << "hello, world!" << std::endl;
    i++;
    return i;
}

void bar(int n){
    std::cout << n << '\n';
}

template<typename... Args>
void foo(Args&&... args) {
    bar(std::forward<decltype(args)>(args)...);
}

template<typename R, typename... Args1>
auto stars2(R(*func)(Args1...)) {
    return [func]<typename... Args2>(Args2&&... args) {
        std::cout << "*******" << std::endl;
        R result = func(std::forward<decltype(args)>(args)...); // forward all arguments
        std::cout << "\n*******" << std::endl;
        return result;
    };
}

//template<typename R, typename... Args1, typename... Args2>
//auto stars3(R(*func)(Args1...)) {
//    return [func](Args2&&... args) {
//        std::cout << "*******" << std::endl;
//        R result = func(std::forward<decltype(args)>(args)...); // forward all arguments
//        std::cout << "\n*******" << std::endl;
//        return result;
//    };
//}

int main() {
    std::cout << "Hello, World!" << std::endl;

    //output(divide_impl)(8, 2);
    int n = 99;
    //std::cout << stars("wq", hello_impl)(n);

    //foo(n);

    std::cout << stars2(hello_impl)(n);

    //std::cout << stars3(hello_impl)(n);
    return 0;
}