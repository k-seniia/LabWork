//#include <iostream>
//
//using namespace std;
//
//bool CheckK(int N, int K) {
//	bool mas[10]{};
//	int count{}, ind{};
//	while (N != 0) {
//		ind = N % 10;
//		N /= 10;
//		if (mas[ind - 1])
//			continue;
//		mas[ind - 1] = true;
//		count++;
//	}
//	return count <= K;
//}
//
//int main() {
//
//	int N, K;
//	cin >> N >> K;
//	cout << boolalpha << CheckK(N, K);
//
//	return 0;
//}