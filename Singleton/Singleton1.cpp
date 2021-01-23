//
// Created by 王强 on 2021/1/23.
// 饿汉模式
#include <iostream>
class Singleton {
public:
    static Singleton* GetInstance() {
        return singleton_;
    }

    static void DestreyInstance() {
        delete singleton_;
    }
    // 防止拷贝和赋值。
    Singleton& operator=(const Singleton&) = delete;
    Singleton(const Singleton& singleton2) = delete;
private:
    // 防止外部构造。
    Singleton() = default;

private:
    static Singleton* singleton_;
};

Singleton* Singleton::singleton_ = new Singleton;

int main() {

    Singleton* s1 = Singleton::GetInstance();
    std::cout << s1 << std::endl;

    Singleton* s2 = Singleton::GetInstance();
    std::cout << s2 << std::endl;

    Singleton::DestreyInstance();

    return 0;
}