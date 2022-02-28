/**
* @file
* @brief
* @details
* @author		qiangwang
* @date		    2022/2/28
* @par Copyright(c): 	2022 mega. All rights reserved.
*/

#include <functional>
#include <iostream>

class Foo {
public:
    std::function<void(void)> f = [this] { doSomething(); };
    void doSomething() {
        std::cout << "do something\n";
    }
    void bindFunction() {
        f();
    }
};

int main(){
    Foo foo;
    foo.bindFunction();
}