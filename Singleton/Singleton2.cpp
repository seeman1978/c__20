//
// Created by 王强 on 2021/1/23.
//

#include <iostream>
#include <mutex>

class Singleton {
public:
    static Singleton* GetInstance() {
        if (!x_init) {
            std::lock_guard<std::mutex> lock(mutex_);
            if (!x_init) {
                instance_ = new Singleton;
                x_init = true;
            }
        }

        return instance_;
    }

    ~Singleton(){
        std::cout << "Destroy Singleton Object\n";
    };

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
    static std::atomic<bool> x_init;
};

Singleton* Singleton::instance_ = nullptr;
std::mutex Singleton::mutex_;
std::atomic<bool> Singleton::x_init{false};

int main() {
    Singleton* s1 = Singleton::GetInstance();
    s1->PrintAddress();

    Singleton* s2 = Singleton::GetInstance();
    s2->PrintAddress();

    //释放内存，只需析构一次
    delete s1;
    //delete s2;

    return 0;
}