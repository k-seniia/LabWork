//#include <thread>
//#include <iostream>
//#include <string>
//using namespace std;
//
//void run(string threadName) {
//	for (int i = 0; i < 10; i++) {
//		string out = threadName + " _ " + to_string(i) + "  id -> ";
//		cout << out << this_thread::get_id() << endl;
//	}
//}
//
//int main() {
//
//	thread t1(run, "t1");
//	thread t2(run, "t2");
//
//	t1.join();
//	t2.join();
//
//	return 0;
//}