#include <future>
#include <thread>
#include <vector>
#include <numeric>
#include <iostream>

/**
* @file
* @brief
* @details
* @author		qiangwang
* @date		    2022/3/11
* @par Copyright(c): 	2022 mega. All rights reserved.
*/

void accumulate(std::promise<int> accumulate_promise)
{
    int sum = 9;
    accumulate_promise.set_value(sum);  // Notify future
}

int main()
{
    // Demonstrate using promise<int> to transmit a result between threads.
    std::promise<int> accumulate_promise;
    std::future<int> accumulate_future = accumulate_promise.get_future();
    std::thread work_thread(accumulate, std::move(accumulate_promise));// must move

    // future::get() will wait until the future has a valid result and retrieves it.
    // Calling wait() before get() is not needed
    //accumulate_future.wait();  // wait for result
    std::cout << "result=" << accumulate_future.get() << '\n';
    work_thread.join();  // wait for thread completion
}
