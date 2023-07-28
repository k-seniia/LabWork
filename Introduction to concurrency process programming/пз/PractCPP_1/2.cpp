//#include <thread>
//#include <iostream>
//#include <string>
//using namespace std;
//
//void run1(string threadName, bool& flag) {
//	for (int i = 0; i < 5; i++)
//		if (flag)
//			cout << threadName << " " << boolalpha << flag << endl;
//}
//
//void run2(bool& flag) {
//	cout << "t2" << boolalpha << flag << endl;
//	flag = false;
//}
//
//int main() {
//
//	bool flag = true;
//
//	thread t1(run1, "t1", ref(flag));
//	thread t2(run2, ref(flag));
//
//	t1.join();
//	t2.join();
//
//	cout << "result - " << boolalpha << flag << endl;
//
//	return 0;
//}