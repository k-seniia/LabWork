//#include <iostream>
//#include <thread>
//#include <string>
//using namespace std;
//
//class MyClass {
//public:
//	void run1(string threadName) {
//		for (int i = 0; i < 10; i++) {
//			string out = threadName + " _ " + to_string(i) + "  id -> ";
//			cout << out << this_thread::get_id() << endl;
//		}
//	}
//	int run2(const int& a, string name) {
//		int b = 1;
//		cout << "ID thread " << name << this_thread::get_id() << " RUN WORK " << endl;
//		for (int i = 0; i < 5; i++) {
//			this_thread::sleep_for(std::chrono::milliseconds(2000));
//			b *= a;
//			cout << b << endl;
//		}
//		this_thread::sleep_for(std::chrono::milliseconds(3000));
//		cout << "ID thread " << this_thread::get_id() << " RUN STOP " << endl;
//		return b;
//	}
//};
//
//int main() {
//	
//	int a = rand() % 10 + 1;
//	int result{};
//	MyClass mc;
//	string str1 = "th1";
//	string str2 = "th2";
//
//	thread t1(&MyClass::run1, mc, str1);
//	thread t2([&]() {result = mc.run2(a, str2); });
//
//	t1.join();
//	t2.join();
//
//	cout << "result = " << result << endl;
//
// 	return 0;
//}