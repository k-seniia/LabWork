//#include <iostream>
//#include <thread>
//#include <vector>
//#include <iomanip>
//using namespace std;
//
//void run(const vector<double>& v1, const vector<double>& v2, int start, int end, double& result) {
//	result = 0;
//	for (int i = start; i < end; ++i)
//		result += v1[i] * v2[i];
//	cout << "Result " << start << "-" << end << " = " << result << endl;
//}
//
//int main() {
//	srand(time(NULL));
//
//	int size = 20;
//	cout << "Size of vector = " << size << endl << endl;
//	vector<double> v1, v2;
//	for (int i = 0; i < size; ++i) {
//		v1.push_back(rand() % 50 + 1);
//		v2.push_back(rand() % 50 + 1);
//		cout << setw(4) << v1[i];
//	}
//	cout << endl;
//	for (int i = 0; i < size; ++i)
//		cout << setw(4) << v2[i];
//	cout << endl << endl;
//
//	int num = 4;
//	vector<double> results(num);
//
//	thread t0(run, ref(v1), ref(v2), 0, 5, ref(results[0]));
//	thread t1(run, ref(v1), ref(v2), 5, 10, ref(results[1]));
//	thread t2(run, ref(v1), ref(v2), 10, 15, ref(results[2]));
//	thread t3(run, ref(v1), ref(v2), 15, 20, ref(results[3]));
//
//	t0.join();
//	t1.join();
//	t2.join();
//	t3.join();
//
//	double result = 0;
//	for (int i = 0; i < num; ++i)
//		result += results[i];
//	cout << "\nScalar product = " << result << endl;
//
//	return 0;
//}