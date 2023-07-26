//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//#include <vector>
//using namespace std;
//
//mutex m;
//condition_variable cv;
//
//void writer(vector<int>& buf) {
//	cout << "thread 1 start\n";
//	for (int i = 0; i < 10; i++) {
//		{
//			std::unique_lock<std::mutex> lock(m);
//			buf.push_back(i);
//			std::cout << "Writer pushed " << i << std::endl;
//		}
//		cv.notify_one();
//		std::this_thread::sleep_for(std::chrono::milliseconds(500));
//	}
//	cout << "thread 1 end\n";
//}
//
//void reader(vector<int>& buf) {
//	cout << "thread 2 start\n";
//	for (int i = 0; i < 10; i++) {
//		std::unique_lock<std::mutex> lock(m);
//		cv.wait(lock, [&buf] { return !buf.empty(); });
//		int val = buf.front();
//		buf.erase(buf.begin());
//		std::cout << "Reader read " << val << std::endl;
//	}
//	cout << "thread 2 end\n";
//}
//
//int main() {
//
//	vector<int> buf;
//
//	thread t1(writer, ref(buf));
//	thread t2(reader, ref(buf));
//
//	t1.join();
//	t2.join();
//
//	return 0;
//}