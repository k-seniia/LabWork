//#include <thread>
//#include <iostream>
//#include <string>
//using namespace std;
//
//void run(int& a, string name) {
//	cout << "ID thread " << name << this_thread::get_id() << " RUN WORK " << endl;
//	for (int i = 0; i < 5; i++) {
//		this_thread::sleep_for(std::chrono::milliseconds(2500));
//		a *= 10;
//		cout << a << endl;
//	}
//	this_thread::sleep_for(std::chrono::milliseconds(3000));
//	cout << "ID thread " << this_thread::get_id() << " RUN STOP " << endl;
//}
//
//int main() {
//
//	int a = rand() % 10 + 1;
//	int b = rand() % 10 + 1;
//	thread th1(run, ref(a), "th1 ");
//	thread th2(run, ref(b), "th2 ");
//
//	cout << "a = " << a << " b = " << b << endl;
//
//	cout << "ID thread " << this_thread::get_id() << " WORK MAIN" << endl;
//	this_thread::sleep_for(std::chrono::milliseconds(10000));
//
//	cout << "a = " << a << " b = " << b << endl;
//
//	th1.detach();
//	th2.detach();
//
//	cout << "a = " << a << " b = " << b << endl;
//
//}