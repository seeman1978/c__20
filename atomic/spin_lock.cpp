//自旋锁
//20221 -6-27

#include <atomic>
#include <iostream>
#include <thread>


std::atomic_flag lock = ATOMIC_FLAG_INIT;	//初始化为false
void f(int n) {
	while (lock.test_and_set(std::memory_order_acquire)) {	//尝试获得锁
		std::cout << "waiting from thread " << n << '\n';
	}
	std::cout << "thread " << n << " starts working" << '\n';
}

void g(int n) {
	std::cout << "thread " << n << " is going to start." << '\n';
	lock.clear();
	std::cout << "thread " << n << " starts working" << '\n';
}
    
int main() {
	lock.test_and_set();	//原子操作
	std::thread t1(f, 1);
	std::thread t2(g, 2);
	t1.join();
	std::this_thread::sleep_for(std::chrono::microseconds(100));
	t2.join();
}