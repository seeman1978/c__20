//
// Created by 王强 on 2021/1/22.
//

#include <iostream>
#include <thread>
#include <mutex>

class X {
    std::recursive_mutex m;
    std::string shared;
public:
    void fun1() {
        std::lock_guard<std::recursive_mutex> lk(m);
        shared = "fun1";
        std::cout << std::this_thread::get_id() << " in fun1, shared variable is now " << shared << '\n';
    }
    void fun2() {
        std::lock_guard<std::recursive_mutex> lk(m);
        shared = "fun2";
        std::cout << std::this_thread::get_id() << " in fun2, shared variable is now " << shared << '\n';
        fun1(); // recursive lock becomes useful here
        std::cout << std::this_thread::get_id() << " back in fun2, shared variable is " << shared << '\n';
    };
};

int main()
{
    {
        X x;
        std::thread t1(&X::fun1, &x);
        std::thread t2(&X::fun2, &x);
        t1.join();
        t2.join();
        std::cout << '\n';
    }
    {
        X x;
        std::thread t1(&X::fun2, &x);
        std::thread t2(&X::fun2, &x);
        t1.join();
        t2.join();
        std::cout << '\n';
    }
    {
        X x;
        std::thread t1(&X::fun2, &x);
        std::thread t2(&X::fun1, &x);
        t1.join();
        t2.join();
        std::cout << '\n';
    }
}