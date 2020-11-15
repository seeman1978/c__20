//
// Created by 王强 on 2020/11/15.
//
#include <mutex>
#include <queue>
#include <thread>
#include <iostream>
template<typename T>
class Sync_queue{
public:
    void put(const T& val){
        std::lock_guard<std::mutex> lck(mtx);
        q.push(val);
        cond.notify_one();
    }
    void put(T&& val){
        std::lock_guard<std::mutex> lck(mtx);
        q.push(std::move(val));
        cond.notify_one();
    }

    void get(T& val){
        std::unique_lock<std::mutex> lck(mtx);
        cond.wait(lck, [this]{return !q.empty();});  //queue为空时，等待
        val = q.front();
        q.pop();
    }

private:
    std::mutex mtx;
    std::condition_variable cond;
    std::queue<T> q;
};

void producer(Sync_queue<int>& mq){
    for (int i = 1; i < 11; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        mq.put(i*i);
    }
}

void consumer(Sync_queue<int>& mq){
    int result {0};
    int val{0};
    for (int i = 1; i < 11; ++i) {
        mq.get(val);
        result += val;
    }
    std::cout << "result is " << result << '\n';
}

int main(){
    {
        Sync_queue<int> mq;
        std::thread t1(producer, std::ref(mq));
        std::thread t2(consumer, std::ref(mq));
        t1.join();
        t2.join();
    }
    {
        Sync_queue<int> mq;
        std::thread t1(producer, std::ref(mq));
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::thread t2(consumer, std::ref(mq));
        t1.join();
        t2.join();
    }

    {
        Sync_queue<int> mq;
        std::thread t2(consumer, std::ref(mq));
        std::thread t1(producer, std::ref(mq));
        t1.join();
        t2.join();
    }
    {
        Sync_queue<int> mq;
        std::thread t2(consumer, std::ref(mq));
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::thread t1(producer, std::ref(mq));
        t1.join();
        t2.join();
    }
}