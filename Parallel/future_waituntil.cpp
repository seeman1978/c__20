//
// Created by 王强 on 2021/1/21.
//

#include <chrono>
#include <future>
#include <iostream>

int main(){
    using namespace std;
    chrono::system_clock::time_point two_seconds_passed
        = std::chrono::system_clock::now() + chrono::seconds(2);
    // Make a future that takes 1 second to complete
    promise<int> p1;
    future<int> f_completes = p1.get_future();
    thread([](promise<int> p1){
            this_thread::sleep_for(chrono::seconds(1));
            p1.set_value_at_thread_exit(9);
        }, move(p1)).detach();

    // Make a future that takes 5 seconds to complete
    promise<int> p2;
    future<int> f_times_out = p2.get_future();
    thread([](promise<int> p2){
        this_thread::sleep_for(chrono::seconds(5));
        p2.set_value_at_thread_exit(8);
    }, move(p2)).detach();

    std::cout << "waiting for 2 seconds..." << '\n';
    if (future_status::ready == f_completes.wait_until(two_seconds_passed)){
        cout << "f_completes: " << f_completes.get() << '\n';
    }
    else{
        cout << "f_completes did not complete!\n";
    }

    if (future_status::ready == f_times_out.wait_until(two_seconds_passed)){
        cout << "f_times_out: " << f_times_out.get() << '\n';
    }
    else{
        cout << "f_times_out did not complete!\n";
    }
    cout << "Done!\n";
}