//
// Created by 王强 on 2021/1/23.
//

#include <iostream>
#include <memory>
#include <mutex>

class Singleton {
public:
    static Singleton& GetInstance() {
        if (!instance_) {
            std::lock_guard<std::mutex> lock(mutex_);
            if (!instance_) {
                instance_.reset(new Singleton);
            }
        }

        return *instance_;
    }

    ~Singleton() = default;

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
};

std::unique_ptr<Singleton> Singleton::instance_;
std::mutex Singleton::mutex_;

int main() {
    Singleton& s1 = Singleton::GetInstance();
    s1.PrintAddress();

    Singleton& s2 = Singleton::GetInstance();
    s2.PrintAddress();

    return 0;
}