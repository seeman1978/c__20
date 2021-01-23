//
// Created by 王强 on 2021/1/23.
//

#include <iostream>
#include <mutex>

class Singleton {
public:
    static Singleton* GetInstance() {
        if (instance_ == nullptr) {
            std::lock_guard<std::mutex> lock(mutex_);
            if (instance_ == nullptr) {
                instance_ = new Singleton;
            }
        }

        return instance_;
    }

    ~Singleton() = default;

    // 释放资源。
    static void Destroy() {
        delete instance_;
        instance_ = nullptr;
    }

    void PrintAddress() const {
        std::cout << this << std::endl;
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    Singleton() = default;

private:
    static Singleton* instance_;
    static std::mutex mutex_;
};

Singleton* Singleton::instance_ = nullptr;
std::mutex Singleton::mutex_;

int main() {
    Singleton* s1 = Singleton::GetInstance();
    s1->PrintAddress();

    Singleton* s2 = Singleton::GetInstance();
    s2->PrintAddress();

    Singleton::Destroy();
    return 0;
}