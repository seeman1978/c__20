//
// Created by 王强 on 2021/1/21.
//

#include <future>
#include <iostream>

int fib(int n){
    if (n < 3) {
        return 1;
    }
    else {
        return fib(n-1) + fib(n-2);
    }
}

int func(int n){
    return n;
}

int main(){
    {
        std::cout << "waiting... " << std::flush;
        const auto start = std::chrono::system_clock::now();
        std::future<int> f1 = std::async(std::launch::async, [](){return fib(40);});
        std::future<int> f2 = std::async(std::launch::async, [](){return fib(43);});

        f1.wait();
        f2.wait();

        const auto diff = std::chrono::system_clock::now() - start;
        std::cout << std::chrono::duration<double>(diff).count() << " seconds\n";

        std::cout << "f1: " << f1.get() << '\n';
        std::cout << "f2: " << f2.get() << '\n';
    }

    {
        std::cout << "waiting... " << std::flush;
        const auto start = std::chrono::system_clock::now();
        int nResult1 = fib(40);
        int nResult2 = fib(43);

        const auto diff = std::chrono::system_clock::now() - start;
        std::cout << std::chrono::duration<double>(diff).count() << " seconds\n";

        std::cout << "f1: " << nResult1 << '\n';
        std::cout << "f2: " << nResult2 << '\n';
    }

    {
        std::cout << "waiting... " << std::flush;
        const auto start = std::chrono::system_clock::now();
        std::future<int> f1 = std::async(std::launch::async, [](){return func(1);});
        std::future<int> f2 = std::async(std::launch::async, [](){return func(2);});

        f1.wait();
        f2.wait();

        const auto diff = std::chrono::system_clock::now() - start;
        std::cout << std::chrono::duration<double>(diff).count() << " seconds\n";

        std::cout << "f1: " << f1.get() << '\n';
        std::cout << "f2: " << f2.get() << '\n';
    }

    {
        std::cout << "waiting... " << std::flush;
        const auto start = std::chrono::system_clock::now();
        int nResult1 = func(1);
        int nResult2 = func(2);

        const auto diff = std::chrono::system_clock::now() - start;
        std::cout << std::chrono::duration<double>(diff).count() << " seconds\n";

        std::cout << "f1: " << nResult1 << '\n';
        std::cout << "f2: " << nResult2 << '\n';
    }
 }