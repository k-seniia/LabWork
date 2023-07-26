//#include <iostream>
//#include <string>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//using namespace std;
//
//mutex m;
//condition_variable cv;
//bool flag = false;
//
//void input(string& s) {
//	cout << "\nInput -> ";
//	unique_lock<mutex>lock(m);
//	while (!flag) {
//		cin >> s;
//		if (s == "aaa") {
//			flag = true;
//			lock.unlock();
//		}
//	}
//	cv.notify_one();
//	cout << "\nInput is ending" << endl;
//}
//
//void proc(string& s) {
//	unique_lock<mutex>lock(m);
//	cout << "Waiting for input" << endl;
//	while (!flag)
//		cv.wait(lock);
//	cout << s;
//	cout << "\nWaiting is ending" << endl;
//}
//
//int main() {
//
//	string s;
//
//	thread t1(proc, ref(s));
//	thread t2(input, ref(s));
//
//	t1.join();
//	t2.join();
//
//	return 0;
//}