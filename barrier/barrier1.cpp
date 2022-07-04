//
// Created by wq on 22-7-1.
//
#include <vector>
#include <iostream>
#include <barrier>

int main(){
    const auto workers = {"anil", "busara", "carl"};
    auto on_completion = []() noexcept {
        static auto phase = "... done\n" "Cleaning up...\n";
        std::cout << phase;
        phase = "... done\n";
    };
    std::barrier sync_point(std::ssize(workers), on_completion);
}