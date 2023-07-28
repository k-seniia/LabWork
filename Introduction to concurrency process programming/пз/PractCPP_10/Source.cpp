#include <thread>
// потокобезпечна черга з блокуваннями
#include "queue.h"
// потокобезчений стек з блокуваннями
#include "stack.h"

// функція для тестування потокобезченого стеку
void test_threadsafe_stack(threadsafe_stack<int>& stk, int num_cyc) {
	for (int i = 0; i < num_cyc; i++)
		if (i % 2 == 0)
			stk.push(i);
		else {
			shared_ptr<int> ptr = stk.pop();
			if (ptr != nullptr) {
				int value = *ptr;
				cout << "Popped value: " << value << endl;
			}
			else
				cout << "Stack is empty!" << endl;
		}
}

// функція для тестування потокобезпечної черги
void test_threadsafe_queue(threadsafe_queue<int>& q, int num_cyc) {
	for (int i = 0; i < num_cyc; i++)
		if (i % 2 == 0)
			q.push(i);
		else {
			shared_ptr<int> ptr = q.wait_and_pop();
			if (ptr != nullptr) {
				int value = *ptr;
				cout << "Popped value: " << value << endl;
			}
			else
				cout << "Queue is empty!" << endl;
		}
}

int main() {
	int num_th = 50; // 4 10 50
	int num_cyc = pow(10, rand() % 2 + 1); // 10 100
	vector<thread> threads;

	// тестування потокобезченого стеку
	threadsafe_stack<int> stk;
	for (int i = 0; i < num_th; i++)
		threads.emplace_back(test_threadsafe_stack, ref(stk), num_cyc);
	for (auto& t : threads)
		t.join();
	threads.clear();

	// тестування потокобезпечної черги
	threadsafe_queue<int> q;
	for (int i = 0; i < num_th; i++)
		threads.emplace_back(test_threadsafe_queue, ref(q), num_cyc);
	for (auto& t : threads)
		t.join();
	threads.clear();

	return 0;
}