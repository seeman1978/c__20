//
// Created by 王强 on 2021/1/22.
//例子来源cppreference

#include <shared_mutex>
#include <iostream>
#include <thread>

class ThreadSafeCounter{
public:
    ThreadSafeCounter() = default;
    // Multiple threads/readers can read the counter's value at the same time.
    unsigned int get() const{
        std::shared_lock lock(m_mutex);
        return m_value;
    }

    // Only one thread/writer can increment/write the counter's value.
    void increment(){
        std::unique_lock lock(m_mutex);
        ++m_value;
    }

    // Only one thread/writer can reset/write the counter's value.
    void reset(){
        std::unique_lock lock(m_mutex);
        m_value = 0;
    }

private:
    mutable std::shared_mutex m_mutex;
    unsigned int m_value = 0;
};

std::mutex mprint;

int main(){
    ThreadSafeCounter counter;

    auto increment_and_print = [&counter](){
        for (int i = 0; i < 3; ++i) {
            counter.increment();
            unsigned int nResult = counter.get();
            std::lock_guard<std::mutex> l(mprint);
            std::cout << std::this_thread::get_id() << ' ' << nResult << '\n';
        }
    };

    std::thread thread1(increment_and_print);
    std::thread thread2(increment_and_print);
    thread1.join();
    thread2.join();
}