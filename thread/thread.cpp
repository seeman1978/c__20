//
// Created by zhaoyue on 2020/11/11.
//

#include <vector>
#include <iostream>
#include <thread>

void my_task(std::vector<double>& arg){
    for (auto v: arg){
        std::cout << v << ' ';
    }
    std::cout << '\n';
}

void test(std::vector<double>& v){
    //std::thread my_thread1{my_task, v}; // copy了一份v传递给my_task
    std::thread my_thread2{my_task, std::ref(v)};   //以引用的方式传递v给my_task
    std::thread my_thread3{[&v]{my_task(v);}};  //也是正确的调用线程传递引用参数的方式，躲避了引用问题
    my_thread2.join();
    my_thread3.join();
}

int main(){
    std::vector<double> v{1.0, 2.0, 3.0};
    test(v);
}