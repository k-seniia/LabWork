//#include <iostream>
//
//using namespace std;
//
//bool IsPower(int N, int K) {
//	if (N == 1)
//		return true;
//	else if (N % K != 0)
//		return false;
//	else
//		return IsPower(N / K, K);
//}
//
//int main() {
//
//	int n, k;
//	cin >> n >> k;
//	cout << boolalpha << IsPower(n, k);
//
//	return 0;
//}