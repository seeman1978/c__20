//
// Created by wq on 2021/3/7.
/// 定长数据、多个生产者、多个消费者
/// 用 -1 表示毒丸

#include <vector>
#include <mutex>
#include <queue>
#include <iostream>
#include <thread>

std::mutex mm;  //互斥锁
std::condition_variable cv; //条件变量
std::queue<int> qPower;
const int nLength = 1000;
int nResult = 0;    //结果

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
    while (true) {
        std::unique_lock<std::mutex> lock {mm}; //获取lock
        cv.wait(lock, []{return !qPower.empty();});          //释放lock，并等待
        auto m = qPower.front();
        if (m == -1){ //毒丸，退出线程
            break;
        }
        else{
            qPower.pop();
            nResult += m;
        }
    }
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
    threads.reserve(num_threads);

    Iterator block_start = first;
    // 创建生产者线程
    for (int i=0; i<(num_threads-2); ++i){
        Iterator block_end = block_start;
        std::advance(block_end, block_size);
        threads.emplace_back(std::thread(producer<Iterator>, block_start, block_end));
        block_start = block_end;
    }
    threads.emplace_back(std::thread(producer<Iterator>, block_start, last));

    //创建消费者线程
    threads.emplace_back(std::thread(consumer));
    threads.emplace_back(std::thread(consumer));

    //等待生产者线程结束
    std::for_each(threads.begin(), threads.end()-2, std::mem_fn(&std::thread::join));
    //队列中放一个毒丸，用于结束消费者
    {
        std::unique_lock<std::mutex> lock {mm};
        qPower.push(-1);
    }
    cv.notify_all();

    //等待消费者线程结束
    std::for_each(threads.end()-2, threads.end(), std::mem_fn(&std::thread::join));
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> vec;
    vec.reserve(nLength);
    for (int i = 1; i < nLength+1; ++i) {
        vec.emplace_back(i);
    }

    parallel_compute(vec.cbegin(), vec.cend());

    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms = stop - start;
    std::cout << "rusult is " << nResult << " took " << ms.count() << " ms\n";
    return 0;
}