//
// Created by 王强 on 2021/3/5.
//

//
// Created by 王强 on 2020/8/28.
//

#include <vector>
#include <mutex>
#include <queue>
#include <iostream>
#include <thread>

std::mutex mm;  //互斥锁
std::condition_variable cv; //条件变量
std::queue<int> qPower;
bool finished =false;

void producer()
{
    std::vector<int> vecSource {1,2,3,4,5,6,7,8,9,10};

    for (auto x : vecSource)
    {
        std::unique_lock<std::mutex> lock {mm};
        int y = x*x;
        std::cout << y << std::endl;
        qPower.push(y);
        cv.notify_one();
    }
    std::this_thread::sleep_for(std::chrono::seconds(10));
    finished= true;
    cv.notify_one();
}

void consumer()
{
    int nResult = 0;
    //这段代码有问题，判断qPower.size() >0时，会出现异常
    while (true)
    {
        std::unique_lock<std::mutex> lock {mm}; //获取lock
        cv.wait(lock, []{return !qPower.empty() || finished;});          //释放lock，并等待
        auto m = qPower.front();
        qPower.pop();
        nResult += m;
        if(finished && qPower.empty()){
            break;
        }
    }

    std::cout << "sum is " << nResult << std::endl;
}

int main()
{
    std::thread t1{producer}, t2{consumer};
    t1.join();
    t2.join();
    return 0;
}