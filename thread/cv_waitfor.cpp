//
// Created by qiangwang on 2021/8/13.
//

#include <iostream>
#include <atomic>
#include <condition_variable>
#include <thread>
#include <chrono>
#include <iomanip>

using namespace std::chrono_literals;

std::condition_variable cv;
std::mutex cv_m;
int i{0};

void waits(int idx)
{
    std::unique_lock<std::mutex> lk(cv_m);
    if(cv.wait_for(lk, idx*10000ms, []{return i == 1;}))
        std::cerr << "Thread " << idx << " finished waiting. i == " << i << '\n';
    else
        std::cerr << "Thread " << idx << " timed out. i == " << i << '\n';
}

int main()
{
    // record start time
    auto start = std::chrono::system_clock::now();
    std::thread t1(waits, 1);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    i = 1;
    t1.join();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end-start;
    std::cout << "Time to wait of " << std::setw(9)
        << " ints : " << diff.count() << " s\n";
}