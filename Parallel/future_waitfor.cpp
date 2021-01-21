//
// Created by 王强 on 2021/1/21.
//

#include <future>
#include <iostream>

int main(){
    std::future<int> f1 = std::async(std::launch::async, [](){
        std::this_thread::sleep_for(std::chrono::seconds(3));
        return 8;
    });
    std::cout << "waiting...\n";
    std::future_status status;
    do {
        status = f1.wait_for(std::chrono::seconds(1));
        switch (status) {
            case std::future_status::deferred:
                std::cout << "deferred\n";
                break;
            case std::future_status::timeout:
                std::cout << "timeout\n";
                break;
            case std::future_status::ready:
                std::cout << "ready!\n";
                break;
        }
    } while (status != std::future_status::ready);
    std::cout << "result is " << f1.get() << '\n';
}