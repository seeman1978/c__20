//
// Created by qiangwang on 2021/9/8.
//

#include <iostream>
#include <thread>

class Test
{
public:
    void runMultiThread(){
        std::cout << "hello world\n";
        std::thread t1(&Test::calculate, this,  0, 10);
        std::thread t2(&Test::calculate, this, 11, 20);
        t1.join();
        t2.join();
    };

    int calculate(int from, int to){
        std::cout << from + to << std::endl;
        return from + to;
    };
};

int main(){
    Test atest;
    std::thread t1(&Test::calculate, &atest,  0, 10);
    std::thread t2(&Test::calculate, &atest, 11, 20);
    t1.join();
    t2.join();

    atest.runMultiThread();
}