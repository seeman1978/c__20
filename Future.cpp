//
// Created by 王强 on 2020/2/22.
//

#include <vector>
#include <queue>
#include <thread>
#include <future>
#include <numeric>
#include <iostream>
#include <chrono>
#include <semaphore>
std::condition_variable cv;
std::mutex cv_m; // This mutex is used for three purposes:
// 1) to synchronize accesses to i
// 2) to synchronize accesses to std::cerr
// 3) for the condition variable cv
int sum = 0;
std::queue<int> queSum;
std::counting_semaphore sema(20);

void accumulate(int nNum)
{
    int nCount = 0;

    do
    {
        sema.acquire();
        {
            std::lock_guard<std::mutex> lk(cv_m);
            sum += queSum.front();
            queSum.pop();
        }

        if (++nCount == nNum){
            break;
        }
    }while (true);
}

void mypower(std::vector<int>::iterator first,
             std::vector<int>::iterator last)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    for (std::vector<int>::iterator i = first; i != last; ++i) {
        int j = (*i)*(*i);
        std::lock_guard<std::mutex> lk(cv_m);
        queSum.push(j);
        sema.release();
    }
}

int main()
{
    // Demonstrate using promise<int> to transmit a result between threads.
    std::vector<int> numbers = { 6 };

    std::thread sum_thread(accumulate, numbers.size());

    std::thread powerthread(mypower, numbers.begin(), numbers.end());

    sum_thread.join();

    // future::get() will wait until the future has a valid result and retrieves it.
    // Calling wait() before get() is not needed
    //accumulate_future.wait();  // wait for result
    std::cout << "result=" << sum << '\n';

}