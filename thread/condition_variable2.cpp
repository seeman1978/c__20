//
// Created by 王强 on 2021/3/5.
//
/// 数据定长，一个生产者、一个消费者

#include <vector>
#include <mutex>
#include <queue>
#include <iostream>
#include <thread>

std::mutex mm;  //互斥锁
std::condition_variable cv; //条件变量
std::queue<int> qPower;
const int nLength = 100;    ///数据长度

template<typename Iterator>
void producer(Iterator first, Iterator last)
{
    for (; first != last; ++first) {
        int y = (*first)*(*first);
        {
            std::unique_lock<std::mutex> lock {mm};
            qPower.push(y);
        }
        cv.notify_one();
    }
}

void consumer()
{
    int nResult = 0;

    for (int i = 1; i < nLength+1; ++i) {
        std::unique_lock<std::mutex> lock {mm}; //获取lock
        cv.wait(lock, []{return !qPower.empty();});          //释放lock，并等待
        auto m = qPower.front();
        qPower.pop();
        nResult += m;
    }

    std::cout << "sum is " << nResult << std::endl;
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<int> vec;
    vec.reserve(nLength);
    for (int i = 1; i < nLength+1; ++i) {
        vec.emplace_back(i);
    }
    std::thread t1{producer<std::vector<int>::const_iterator>, vec.cbegin(), vec.cend()}, t2{consumer};
    t1.join();
    t2.join();

    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms = stop - start;
    std::cout << "took " << ms.count() << " ms\n";
    return 0;
}