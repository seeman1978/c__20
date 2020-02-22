//
// Created by 王强 on 2020/2/22.
//

#include <vector>
#include <thread>
#include <future>
#include <numeric>
#include <iostream>
#include <chrono>

void accumulate(int nNum,
                std::promise<int> accumulate_promise,
                std::future<int> barrier_future)
{
    int nCount = 0;
    int sum = 0;
    do
    {
        sum += barrier_future.get();
        if (++nCount == nNum){
            break;
        }
    }while (true);

    accumulate_promise.set_value(sum);  // Notify future
}

void mypower(std::vector<int>::iterator first,
             std::vector<int>::iterator last,
             std::promise<int> barrier)
{
    for (std::vector<int>::iterator i = first; i != last; ++i) {
        int j = (*i)*(*i);
        barrier.set_value(j);
    }
}

int main()
{
    // Demonstrate using promise<int> to transmit a result between threads.
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6 };
    std::promise<int> barrier;
    std::future<int> barrier_future = barrier.get_future();
    std::thread new_work_thread(mypower, numbers.begin(), numbers.end(), std::move(barrier));


    std::promise<int> accumulate_promise;
    std::future<int> accumulate_future = accumulate_promise.get_future();
    std::thread work_thread(accumulate, numbers.size(),
                            std::move(accumulate_promise), std::move(barrier_future));

    // future::get() will wait until the future has a valid result and retrieves it.
    // Calling wait() before get() is not needed
    //accumulate_future.wait();  // wait for result
    std::cout << "result=" << accumulate_future.get() << '\n';
    work_thread.join();
}