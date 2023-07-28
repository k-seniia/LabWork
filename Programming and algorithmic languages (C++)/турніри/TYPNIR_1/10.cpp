//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//int main() {
//
//	int n{}, a[100]{}, l{}, r{}, sum{}; bool ll = 1;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//		if (a[i] % 2 == 0 && ll) {
//			l = i;
//			ll = 0;
//			continue;
//		}
//		if (a[i] % 2 == 0 && i != l)
//			r = i;
//	}
//	for (int i = l; i <= r; i++)
//		if (a[i] > 0)
//			sum += a[i];
//	cout << sum;
//
//	return 0;
//}