//
// Created by zhaoyue on 2020/9/16.
//

#include <mutex>
#include <thread>
#include <chrono>
#include <iostream>

struct Box{
    explicit Box(int num) : num_things{num}
    {

    }

    int num_things;
    std::mutex m;
};

void transfer(Box& from, Box& to, int num)
{
    std::unique_lock<std::mutex> fromLock{from.m, std::defer_lock};
    std::unique_lock<std::mutex> toLock{to.m, std::defer_lock};

    std::lock(fromLock, toLock);

    from.num_things -= num;
    to.num_things += num;

    std::cout << "from num is " << from.num_things << std::endl;
    std::cout << "to num is " << to.num_things << std::endl;
}

int main()
{
    Box acc1{100};
    Box acc2{50};
    std::thread t1{transfer, std::ref(acc1), std::ref(acc2), 10};
    std::thread t2{transfer, std::ref(acc2), std::ref(acc1), 5};
    t1.join();
    t2.join();
}