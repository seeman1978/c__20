#include <thread>
#include <iostream>
#include <atomic>

std::atomic<int> a{ 0 }, b{ 0 };

void thread1() {
	int t = 1;
	a.store(t, std::memory_order_relaxed);
	b.store(2, std::memory_order_relaxed);
}

void thread2() {
	while (b.load(std::memory_order_relaxed) != 2)
	{//自选等待
		;
	}
	std::cout << a.load(std::memory_order_relaxed) << '\n';	//a可能是0，也可能是1
}

int main() {
	std::thread t1{ thread1 };
	std::thread t2{ thread2 };
	t1.join();
	t2.join();
	return 0;
}