#include <atomic>
#include <thread>
#include <iostream>
std::atomic<int> a;
std::atomic<int> b;

void thread1() {
	int t = 1;
	a = t;
	b = 2;
}

void thread2() {
	while (b != 2)
	{
		;
	}
	std::cout << a << '\n';
}

int main() {
	std::thread t1(thread1);
	std::thread t2(thread2);
	t1.join();
	t2.join();
}