//
// Created by wq on 2021/1/21.
//

#include <cmath>
#include <future>
#include <iostream>

int f(int x, int y){
    return std::pow(x, y);
}

void task_lambda(){
    std::packaged_task<int(int, int)> task([](int a, int b){
        return std::pow(a, b);
    });
    std::future<int> result = task.get_future();
    task(2, 9);
    std::cout << "task lambda:\t" << result.get() << '\n';
}

void task_bind(){
    std::packaged_task<int()> task(std::bind(f, 2, 11));
    std::future<int> result = task.get_future();
    task();
    std::cout << "task bind:\t" << result.get() << '\n';
}

void task_thread(){
    std::packaged_task<int(int,int)> task(f);
    std::future<int> result = task.get_future();

    std::thread task_td(std::move(task), 2, 10);
    task_td.join();

    std::cout << "task_thread:\t" << result.get() << '\n';
}

int main()
{
    task_lambda();
    task_bind();
    task_thread();
}