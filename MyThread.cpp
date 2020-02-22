//
// Created by 王强 on 2020/2/21.
//

#include <iostream>
#include <thread>

void foo()
{
    std::cout << "thread id " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::atomic<int> cnt = 0;       /// 多线程访问该变量时，是一个原子操作
    auto f = [&]{std::cout << cnt++ << std::endl;};
    std::thread t1{f}, t2{f}, t3{f};
    std::cout << "after starting, joinable: " << std::boolalpha << t1.joinable() << t2.joinable()  << t3.joinable() << '\n';
    if (t1.joinable() && t2.joinable() && t3.joinable())
    {
        t1.join();
        t2.join();
        t3.join();
    }

    std::cout << "after joining, joinable: " << t1.joinable() << t2.joinable()  << t3.joinable() << '\n';

    std::thread t4(foo), t5(foo);
    std::cout << "t4's id: " << t4.get_id() << '\n';
    std::cout << "t5's id: " << t5.get_id() << '\n';

    t4.join();
    t5.join();

    return 0;
}
