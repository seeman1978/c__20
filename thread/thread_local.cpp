#include <string>
#include <iostream>
#include <thread>

/**
* @file
* @brief
* @details
* @author		qiangwang
* @date		    2021/10/12
* @par Copyright(c): 	2021 mega. All rights reserved.
*/

class A {
public:
    A()=default;
    ~A()=default;

    void test(const std::string &name) {
        thread_local int count = 0;
        ++count;
        std::cout << "class A " << name << ": " <<  count << std::endl;
    }
};

class B {
public:
    B()=default;
    ~B()=default;

    void test(const std::string &name) {
        static int count = 0;
        ++count;
        std::cout << "class B " << name << ": " <<  count << std::endl;
    }
};

void funcA(const std::string &name) {
    A a1;
    a1.test(name);
    a1.test(name);
    A a2;
    a2.test(name);
    a2.test(name);
}

void funcB(const std::string &name) {
    B b1;
    b1.test(name);
    b1.test(name);
    B b2;
    b2.test(name);
    b2.test(name);
}

int main(int argc, char* argv[]) {
    std::thread t1(funcA, "t1");
    t1.join();
    std::thread t2(funcA, "t2");
    t2.join();

    std::thread t3(funcB, "t3");
    t3.join();
    std::thread t4(funcB, "t4");
    t4.join();
    return 0;
}
