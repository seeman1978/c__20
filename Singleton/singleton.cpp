//
// Created by zhaoyue on 2020/11/15.
//

#include <iostream>

class Singleton
{
private:
    Singleton()=default;

public:
    static Singleton& GetInstance()
    {
        static Singleton INSTANCE;
        return INSTANCE;
    }

    ~Singleton() = default;

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

int main() {
    Singleton &s1 = Singleton::GetInstance();
    std::cout << &s1 << std::endl;

    Singleton &s2 = Singleton::GetInstance();
    std::cout << &s2 << std::endl;

    return 0;
}