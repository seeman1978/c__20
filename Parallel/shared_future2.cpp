//
// Created by wq on 23-12-19.
//

#include <vector>
#include <future>
#include <iostream>

int32_t func(int32_t input){
    return input;
}

int main(){
    std::vector<std::shared_future<int32_t>> vec_futures;
    for (int i = 0; i < 3; ++i) {
        std::shared_future<int32_t> f = std::async(std::launch::async, [&i](){
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(100ms);
            return func(i);
        });
        vec_futures.emplace_back(f);
    }

    for (const auto& f : vec_futures) {
        std::cout << "result:" << f.get() << '\n';
    }

    return 0;
}