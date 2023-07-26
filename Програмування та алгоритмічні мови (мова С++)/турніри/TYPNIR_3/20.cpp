//#include <iostream>
//
//using namespace std;
//
//bool IsPrimePower(int n) {
//	int s = 1;
//	for (int p = 1, k = 1; p < n; p++) {
//		s = 1;
//		for (int i = 0; i < k; i++)
//			s *= p;
//		if (s * p > n) {
//			k++;
//			p = 1;
//		}
//		if (s == n)
//			return true;
//	}
//	return false;
//}
//
//int main() {
//
//	int n; cin >> n;
//	cout << boolalpha << IsPrimePower(n);
//
//	return 0;
//}