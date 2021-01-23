//
// Created by 王强 on 2021/1/23.
// 例子来源c++标注库第2版

#include <queue>
#include <mutex>
#include <thread>
#include <iostream>
#include <future>

std::queue<int> g_queue;
std::mutex g_queueMuetx;
std::condition_variable g_queueCV;

void provider(int val){
    for (int i = 0; i < 6; ++i) {
        {
            std::lock_guard<std::mutex> lg(g_queueMuetx);
            g_queue.push(val+i);
        }
        g_queueCV.notify_one();
        std::this_thread::sleep_for(std::chrono::milliseconds(val));
    }
}

void consumer(int num){
    while (true){
        int val;
        {
            std::unique_lock<std::mutex> ul(g_queueMuetx);
            g_queueCV.wait(ul, []{return !g_queue.empty();});
            val = g_queue.front();
            g_queue.pop();
        }
        std::cout << "consumer " << num << ": " << val << '\n';
    }
}

int main(){
    auto p1 = std::async(std::launch::async, provider, 100);
    auto p2 = std::async(std::launch::async, provider, 300);
    auto p3 = std::async(std::launch::async, provider, 500);

    auto c1 = std::async(std::launch::async, consumer, 1);
    auto c2 = std::async(std::launch::async, consumer, 2);
}