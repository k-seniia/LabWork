//#include <thread>
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//void run(int& a) {
//	a *= 10;
//	cout << a << endl;
//}
//
//int main() {
//	srand(time(NULL));
//
//	int max = thread::hardware_concurrency();
//	cout << "Enter the number of threads from 2 to " << max << " -> ";
//	int num = rand() % (max - 2) + 2; cout << num << endl;//cin >> num;
//
//	vector<thread> threads;
//	int a = rand() % 10 + 1;
//	for (int i = 0; i < num; ++i) {
//		threads.emplace_back(run, ref(a));
//	}
//
//	for (auto& t : threads)
//		t.join();
//
//	return 0;
//}