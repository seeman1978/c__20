#include <thread>
#include <condition_variable>
#include <iostream>

/**
* @file
* @brief
* @details
* @author		qiangwang
* @date		    2022/1/11
* @par Copyright(c): 	2022 mega. All rights reserved.
*/

std::condition_variable cv_;
std::mutex m_;

int main(){
    std::thread t1{[](){
        cv_.notify_one();   //notify will miss
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(5000ms);
    }}, t2{[](){
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(2000ms);
        std::unique_lock<std::mutex> lock{m_};
        cv_.wait(lock);
        std::cout << "finish\n";
    }};
    t1.join();
    t2.join();
}