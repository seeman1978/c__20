#include <iostream>
#include <thread>

std::counting_semaphore cs1{0};
std::counting_semaphore cs2{2};

int main() {
    std::cout << "Hello, World!" << std::endl;

    cs2.acquire();

    std::cout << "Hello, World 1!" << std::endl;

    std::thread t1{[]{
        std::cout << "Hello, World 2!" << std::endl;
        cs1.release();
    }};

    cs1.acquire();

    std::cout << "Hello, World 3!" << std::endl;

    t1.join();

    return 0;
}
