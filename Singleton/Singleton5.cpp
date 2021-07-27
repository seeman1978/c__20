//
// Created by 王强 on 2021/1/23.
//

#include <iostream>
#include <memory>
#include <mutex>
#include <atomic>
class Singleton {
public:
    static Singleton* GetInstance() {
        if (!x_init) {
            std::lock_guard<std::mutex> lock(mutex_);
            if (!x_init) {
                instance_.reset(new Singleton);
                x_init = true;
            }
        }

        return instance_.get();
    }
    ~Singleton() {
        std::cout << "destory\n";
    };
    void PrintAddress() const {
        std::cout << this << std::endl;
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
private:
    Singleton() = default;

private:
    static std::unique_ptr<Singleton> instance_;
    static std::mutex mutex_;
    static std::atomic<bool> x_init;
};

std::unique_ptr<Singleton> Singleton::instance_;
std::mutex Singleton::mutex_;
std::atomic<bool> Singleton::x_init{false};

int main() {
    Singleton* p1 = Singleton::GetInstance();
    p1->PrintAddress();

    //delete p1;

    Singleton* p2 = Singleton::GetInstance();
    p2->PrintAddress();

    return 0;
}