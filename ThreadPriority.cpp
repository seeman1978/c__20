//
// Created by 王强 on 2020/2/21.
//

#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>
#include <cstring>
#include <pthread.h>

std::mutex iomutex;
void f(int num)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));

    sched_param sch;
    int policy;
    pthread_getschedparam(pthread_self(), &policy, &sch);
    std::lock_guard<std::mutex> lk(iomutex);
    std::cout << "Thread " << num << " is executing at priority "
              << sch.sched_priority << '\n';
}

int main()
{
    unsigned int n = std::thread::hardware_concurrency();
    std::cout << n << " concurrent threads are supported.\n";
    std::thread t1(f, 1), t2(f, 2);

    sched_param sch;
    int policy;
    pthread_getschedparam(t1.native_handle(), &policy, &sch);
    sch.sched_priority = 40;
    if (pthread_setschedparam(t1.native_handle(), SCHED_FIFO, &sch)) {
        std::cout << "Failed to setschedparam: " << std::strerror(errno) << '\n';
    }

    std::cout << "thread 1 id: " << t1.get_id() << std::endl;
    std::cout << "thread 2 id: " << t2.get_id() << std::endl;

    std::swap(t1, t2);

    std::cout << "after std::swap(t1, t2):" << std::endl;
    std::cout << "thread 1 id: " << t1.get_id() << std::endl;
    std::cout << "thread 2 id: " << t2.get_id() << std::endl;

    t1.join();
    t2.join();
}