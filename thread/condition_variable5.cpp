//
// Created by 王强 on 2021/3/5.
//

#include <vector>
#include <mutex>
#include <queue>
#include <iostream>
#include <thread>

std::mutex mm;  //互斥锁
std::condition_variable cv; //条件变量
std::queue<int> qPower;
const int nLength = 100;

template<typename Iterator>
void producer(Iterator first, Iterator last)
{
    for (; first != last; ++first) {
        int y = (*first)*(*first);
        std::unique_lock<std::mutex> lock {mm};
        qPower.push(y);
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


template <typename Iterator>
void parallel_compute(Iterator first, Iterator last){
    unsigned long const length = std::distance(first, last);
    if (length == 0){
        return;
    }

    unsigned long const min_per_thread = 25;
    unsigned long const max_threads = (length+min_per_thread-1)/min_per_thread;

    unsigned long const hardware_threads =
            std::thread::hardware_concurrency();
    int const num_threads =
            std::min(hardware_threads!=0 ? hardware_threads : 2, max_threads);
    unsigned long const block_size = length/(num_threads-1);

    std::vector<std::thread> threads;
    threads.reserve(num_threads-1); //有一个计算可以在主线程里做

    Iterator block_start = first;
    // 创建生产者线程
    for (int i=0; i<(num_threads-2); ++i){
        Iterator block_end = block_start;
        std::advance(block_end, block_size);
        threads.emplace_back(std::thread(producer<Iterator>, block_start, block_end));
        block_start = block_end;
    }

    //创建消费者线程
    threads.emplace_back(std::thread(consumer));
    producer<Iterator>(block_start, last);

    //等待线程结束
    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
}

int main()
{
    std::vector<int> vec;
    vec.reserve(nLength);
    for (int i = 1; i < nLength+1; ++i) {
        vec.emplace_back(i);
    }

    parallel_compute(vec.begin(), vec.end());

    return 0;
}