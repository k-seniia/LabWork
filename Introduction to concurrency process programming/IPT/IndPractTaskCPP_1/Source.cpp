#include <iostream>
#include <thread>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

int fact(int i) {
	if (i == 0) return 1;
	else return i * fact(i - 1);
}

float ser(const float& x, const int& start, const int& end) {
	float m{};
	for (int n = start; n < end; n++)
		m += (fact(2 * n) / (pow(4, n) * pow(fact(n), 2) * (2. * n + 1))) * pow(x, 2 * n + 1);
	return m;
}

int main() {
	srand(time(NULL));

	int n = thread::hardware_concurrency(), s = 34 / n; //max 34
	float x = (rand() % 200) / 100. - 1, asin_x{};
	cout << "x = " << x << endl;

	vector<thread> threads;
	vector<float> m(n);

	int start{}, end{};
	for (int i = 0; i < n; i++) {
		start = i * s;
		end = (i + 1) * s;
		threads.emplace_back([=, &m]() { m[i] = ser(x, start, end); });
	}
	for (auto& t : threads)
		t.join();

	for (int i = 0; i < n; i++)
		asin_x += m[i];

	cout << "arcsin(x) = " << fixed << setprecision(10) << asin_x;
}