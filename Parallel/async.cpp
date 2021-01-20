//
// Created by wq on 2021/1/20.
//

#include <random>
#include <thread>
#include <iostream>
#include <future>

int doSomething(char c){
    using namespace std;
    std::default_random_engine dre(c);
    std::uniform_int_distribution<int> id(10, 1000);
    for (int i = 0; i < 10; ++i) {
        this_thread::sleep_for(chrono::milliseconds(id(dre)));
        cout.put(c).flush();
    }
    return c;
}

int func1(){
    return doSomething('.');
}

int func2(){
    return doSomething(',');
}

//如何给async的函数传参数？
int main(){
    using namespace std;
    cout << "starting func1 in background and func2 in foreground:" << '\n';
    future<int> result1(async(func1));
    int result2 = func2();
    //将async和get之间的距离最大化，原则是早调用，晚返回。
    int result = result1.get() + result2;
    cout << "\nresult of func1 + func2: " << result << '\n';
}