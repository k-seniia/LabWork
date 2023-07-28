//#include <iostream>
//
//using namespace std;
//
//bool CheckABC(int N, int A, int B, int C) {
//	int n{};
//	while (N > 0) {
//		n = N % 10;
//		if (n == A || n == B || n == C)
//			N /= 10;
//		else
//			return false;
//	}
//	return true;
//}
//
//int main() {
//
//	int N, A, B, C;
//	cin >> N >> A >> B >> C;
//	cout << boolalpha << CheckABC(N, A, B, C);
//
//	return 0;
//}