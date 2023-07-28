#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

struct Monts {
	string name;
	int temp{};
};

void sortM(vector<Monts>& mon, int end) {
	sort(mon.begin(), mon.begin() + end,
		[](const Monts& m1, const Monts& m2) {	return m1.temp < m2.temp; });
}

int main() {

	vector<Monts> mon{
		{ "January", -4}, { "February", -3 }, { "March", 2 }, { "April", 9 },
		{ "May", 16 }, { "June", 19 }, { "July", 21 }, { "August", 20 },
		{ "September", 14 }, { "October", 8 }, { "November", 2 }, { "December", -2 }
	};

	//thread th (sortM, ref(mon));
	//th.join();

	vector<thread> threads;

	int num = thread::hardware_concurrency();
	int size = mon.size() / num;

	int end;
	for (int i = 0; i < num; i++) {
		end = (i + 1) * size;
		threads.emplace_back([=, &mon]() { sortM(ref(mon), end); });
	}

	for (auto& t : threads)
		t.join();

	for (auto& m : mon)
		cout << m.name << " :  " << m.temp << endl;
}