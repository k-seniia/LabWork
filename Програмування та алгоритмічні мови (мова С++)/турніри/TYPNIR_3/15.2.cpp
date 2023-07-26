//#include <iostream>
//
//using namespace std;
//
//bool AreTheDigitsOrdered(int N) {
//	int vN[10], iN{};
//	while (N > 0) {
//		vN[iN++] = (N % 10);
//		N /= 10;
//	}
//	bool flag = true, ml{};
//	for (int i = 0; i < iN - 1; i++) {
//		if (flag) {
//			if (vN[i] > vN[i + 1]) {
//				ml = 1;
//				flag = false;
//			}
//			if (vN[i] < vN[i + 1]) {
//				ml = 0;
//				flag = false;
//			}
//		}
//		else {
//			if (ml == 0)
//				if (vN[i] > vN[i + 1])
//					return false;
//			if (ml == 1)
//				if (vN[i] < vN[i + 1])
//					return false;
//		}
//	}
//	return true;
//}
//
//int main() {
//
//	int n;
//	cin >> n;
//	cout << boolalpha << AreTheDigitsOrdered(n);
//
//	return 0;
//}