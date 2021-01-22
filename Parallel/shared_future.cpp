#include <future>
#include <iostream>

//
// Created by 王强 on 2021/1/22.
//
//例子来源cppreference
int main(){
    using namespace std;
    promise<void> ready_promise, t1_ready_promise, t2_ready_promise;
    shared_future<void> ready_future(ready_promise.get_future());

    chrono::time_point<chrono::high_resolution_clock> start;
    auto fun1 = [&, ready_future]()->chrono::duration<double, milli>{
        t1_ready_promise.set_value();
        ready_future.wait();
        return chrono::high_resolution_clock::now() - start;
    };

    auto fun2 = [&, ready_future]()->chrono::duration<double, milli> {
        t2_ready_promise.set_value();
        ready_future.wait();
        return chrono::high_resolution_clock::now() - start;
    };

    auto fut1 = t1_ready_promise.get_future();
    auto fut2 = t2_ready_promise.get_future();

    auto result1 = async(launch::async, fun1);
    auto result2 = async(launch::async, fun2);

    fut1.wait();
    fut2.wait();

    start = chrono::high_resolution_clock::now();
    ready_promise.set_value();

    cout << "Thread 1 received the signal " << result1.get().count() << " ms after start \n"
        << "Thread 2 received the signal " << result2.get().count() << " ms after start \n";
}