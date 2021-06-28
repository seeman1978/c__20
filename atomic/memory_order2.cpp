#include <thread>
#include <atomic>
#include <iostream>

std::atomic<int> a{ 0 };
std::atomic<int> b{ 0 };

void valueSet() {
	int t = 1;
	a.store(t, std::memory_order_relaxed);	//表示松散的内存模型
	b.store(2, std::memory_order_relaxed);
}

void observer() {
	std::cout << "(" << a << ", " << b << ")" << '\n';	//可能有多种输出，打印出0，2这样的结果也是合理的
}

int main() {
	std::thread t1{ valueSet };
	std::thread t2{ observer };
	t1.join();
	t2.join();
	std::cout << "got (" << a << ", " << b << ")" << '\n';
	return 0;
}