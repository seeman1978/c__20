//
// Created by zhaoyue on 2020/11/15.
//

#include <string>
#include <iostream>

class Singleton
{
private:
    Singleton()=default;

public:
    static Singleton& instance()
    {
        static Singleton INSTANCE;
        return INSTANCE;
    }
};

int main()
{
   Singleton s = Singleton::instance();
}
