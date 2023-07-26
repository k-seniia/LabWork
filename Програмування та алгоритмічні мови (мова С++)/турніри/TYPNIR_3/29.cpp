//#include <iostream>
//
//using namespace std;
//
//int NSD(int a, int b) {
//	if (b == 0) return a;
//	return NSD(b, a % b);
//}
//
//int main() {
//
//	int N{}; cin >> N;
//	int A = N / 2, B = N - A, max{}, mA{}, mB{};
//	int nsd{};
//
//	while (A > 0) {
//		nsd = NSD(A, B);
//		if (nsd > max) {
//			max = nsd;
//			mA = A; mB = B;
//		}
//		A--; B++;
//	}
//
//	cout << mA << " " << mB;
//
//	return 0;
//}