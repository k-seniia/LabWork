//#include <iostream>
//#include <cmath>
//#include <vector>
//
//using namespace std;
//
//int main() {
//
//	int k{}; cin >> k;
//	int x{}, y{}, min{}, max{};
//	int a[100000]{};
//	for (int n = 0; n < 100000; n++)
//		a[n] = (n * n) % 12345 + (n * n * n) % 23456;
//
//	for (int i = 0; i < k; i++) {
//		cin >> x >> y;
//		if (x > 0) {
//			min = a[x]; max = a[x];
//			for (int j = x + 1; j <= y; j++) {
//				if (min > a[j])
//					min = a[j];
//				if (max < a[j])
//					max = a[j];
//			}
//			cout << max - min << endl;
//		}
//		else if (x < 0)
//			a[-x] = y;
//	}
//
//	return 0;
//}