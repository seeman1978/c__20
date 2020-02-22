//
// Created by 王强 on 2020/2/22.
//
#include <iostream>       // std::cout
#include <atomic>         // std::atomic, std::atomic_flag, ATOMIC_FLAG_INIT
#include <thread>         // std::thread, std::this_thread::yield
#include <vector>         // std::vector


std::atomic<bool> ready(false);
std::atomic_flag winner = ATOMIC_FLAG_INIT;

struct A { int a[4]; };     /// 超过4，编译就会报错。
struct B { int x, y; };

void do_count1m(int id)
{
    while (!ready) {
        std::this_thread::yield();
    } // 等待 ready 变为 true.

    for (volatile int i=0; i<1000000; ++i) {

    } // 计数

    if (!winner.test_and_set()) {
        std::cout << "thread #" << id << " won!\n";
    }
}

int main ()
{
    std::vector<std::thread> threads;
    std::cout << "spawning 10 threads that count to 1 million...\n";
    for (int i=1; i<=10; ++i) {
        threads.push_back(std::thread(do_count1m, i));
    }
    ready = true;

    for (auto& th : threads) {
        th.join();
    }

    std::cout << std::boolalpha
              << "std::atomic<A> is lock free? "
              << std::atomic<A>{}.is_lock_free() << '\n'
              << "std::atomic<B> is lock free? "
              << std::atomic<B>{}.is_lock_free() << '\n';

    return 0;
}