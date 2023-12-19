//
// Created by 王强 on 2020/11/10.
//

#include <array>
#include <iostream>
#include <atomic>

//X上的操作有没有锁，没锁，返回true；有锁，返回false
struct A{
    std::array<int, 100> a; //a[100]
};

struct B{
    int x, y;
};

int main(){
    std::cout << std::boolalpha
        << "std::atomic<A> is lock free? "
        << std::atomic<A>{}.is_lock_free() << '\n'
        << "std::atomic<B> is lock free? "
        << std::atomic<B>{}.is_lock_free() << '\n';
}