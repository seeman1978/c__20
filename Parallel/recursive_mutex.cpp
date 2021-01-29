//
// Created by 王强 on 2021/1/22.
// 不建议在程序中使用递归互斥锁。如果确实出现需要使用递归互斥锁的场景，你需要从程序设计的角度出发进行改动，来规避递归互斥锁的需求。
// 比如下例，你可以通过定义第三个函数，将其作为私有成员函数，，并且让其他成员函数都对其进行调用，
// 这个私有成员函数不会对互斥量进行上锁(在调用前必须获得锁)。然后，你仔细考虑一下，在这种情况调用新函数时，数据的状态。

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