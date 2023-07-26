//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//	int n{}, a[100]{}, l{}, r{}, min{}; bool ll = 1, rr = 1;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//		if (a[i] % 2 != 0 && ll) {
//			l = i;
//			ll = 0;
//			continue;
//		}
//		if (a[i] % 2 != 0 && i != l && rr) {
//			r = i;
//			rr = 0;
//		}
//	}
//	min = a[r];
//	for (int i = l; i < r; i++)
//		if (a[i] < min)
//			min = a[i];
//	cout << min;
//
//	return 0;
//}