//
// Created by wq on 2020/7/17.
//

#include <iostream>
#include <vector>
#include <thread>
int f()
{
    static int i = 0;
    synchronized { // 开始同步块
            std::cout << i << " -> ";
            ++i;       // 每次调用 f() 都获得 i 的唯一值
            std::cout << i << '\n';
            return i; // 结束同步块
    }
}
int main()
{
    std::vector<std::thread> v(10);
    for(auto& t: v)
        t = std::thread([]{ for(int n = 0; n < 10; ++n) f(); });
    for(auto& t: v)
        t.join();
}