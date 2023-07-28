//#include <thread>
//#include <iostream>
//#include <string>
//#include <vector>
//#include <random>
//#include <cmath>
//using namespace std;
//
//void calcA(vector<float>& x) {
//	double A = 0;
//	for (int i = 0; i < x.size(); i++) {
//		this_thread::sleep_for(chrono::milliseconds(1500));
//		A += cbrt(x[i] * sin(pow(x[i], 2)));
//		cout << " A" << i << " = " << A << endl;
//	}
//	cout << "\tA = " << A << endl;
//}
//void calcB(vector<float>& y) {
//	double B = 0;
//	for (int i = 0; i < y.size(); i++) {
//		this_thread::sleep_for(chrono::milliseconds(1500));
//		B += cbrt(y[i] * sin(pow(y[i], 2)));
//		cout << " B" << i << " = " << B << endl;
//	}
//	cout << "\tB = " << B << endl;
//}
//
//int main() {
//	srand(time(NULL));
//
//	const int Nx = 10, Ny = 15;
//	vector<float> x, y;
//	for (int i = 0; i < Nx; i++) {
//		x.push_back(rand() % 26);
//		cout << x[i] << " ";
//	}
//	cout << endl;
//	for (int i = 0; i < Ny; i++) {
//		y.push_back(rand() % 21 - 10);
//		cout << y[i] << " ";
//	}
//	cout << endl << endl;
//
//	//calcA(ref(x));
//	//calcB(ref(y));
//
//	thread t0(calcA, ref(x));
//	thread t1(calcB, ref(y));
//
//	//this_thread::sleep_for(chrono::milliseconds(1000));
//
//	t0.join();
//	t1.join();
//
//}