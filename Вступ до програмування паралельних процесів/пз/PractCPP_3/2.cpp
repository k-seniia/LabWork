//#include <iostream>
//#include <thread>
//using namespace std;
//
//int run(int a, int b) {
//	cout << "a = " << a << ", b = " << b << endl;
//	return a * b;
//}
//
//int main() {
//	srand(time(NULL));
//
//	int result{}, a = rand() % 10 + 1, b = rand() % 10 + 1;
//	
//	thread th([a, b, &result]() {result = run(a, b); });
//
//	th.join();
//
//	cout << "result = " << result << endl;
// 
// 	return 0;
//}