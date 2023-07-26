//#include <iostream>
//
//using namespace std;
//
//bool CheckBinaryDigits(int N, int K) {
//	int count{};
//	while (N > 0) {
//		if (N % 2 == 1)
//			count++;
//		N /= 2;
//	}
//	if (count > K)
//		return false;
//	else
//		return true;
//}
//
//int main() {
//
//	int N, K;
//	cin >> N >> K;
//	cout << boolalpha << CheckBinaryDigits(N, K);
//
//	return 0;
//}