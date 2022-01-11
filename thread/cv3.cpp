/**
* @file
* @brief
* @details
* @author		qiangwang
* @date		    2022/1/11
* @par Copyright(c): 	2022 mega. All rights reserved.
*/
#include <thread>
#include <condition_variable>
#include <iostream>
std::condition_variable cv_;
std::mutex m_;
using namespace std::chrono_literals;
int count_{1};
int main(){
    std::thread t1{[](){
        std::this_thread::sleep_for(5000ms);
        cv_.notify_one();   //notify will miss
    }}, t2{[](){
        do {
            std::unique_lock<std::mutex> lock{m_};
            cv_.wait(lock, []{return count_ > 0;});
            std::cout << count_++ <<" finish\n";
            std::this_thread::sleep_for(2000ms);
        } while (true);
    }};
    t1.join();
    t2.join();
}