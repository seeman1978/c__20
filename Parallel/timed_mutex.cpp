//
// Created by 王强 on 2021/1/22.
//

#include <mutex>
#include <sstream>
#include <thread>
#include <iostream>
#include <vector>

std::mutex cout_mutex;
std::timed_mutex tmutex;

void job(int id){
    std::ostringstream stream;
    for (int i = 0; i < 3; ++i) {
        if (tmutex.try_lock_for(std::chrono::milliseconds(5000))){
            stream << "success ";
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
        else {
            stream << "failed ";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << "[" << id << "]" << stream.str() << '\n';
}

int main(){
    std::vector<std::thread> threads;
    for (int i = 0; i < 4; ++i) {
        threads.emplace_back(job, i);
    }
    for (auto& i: threads) {
        i.join();
    }
}