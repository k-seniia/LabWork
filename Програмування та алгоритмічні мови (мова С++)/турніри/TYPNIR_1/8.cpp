//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//	int n{}, a[100]{}, l{}, min = 100, r{}, max = -100, sum{};
//
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//		if (a[i] < min) {
//			min = a[i];
//			l = i;
//		}
//		if (a[i] >= max) {
//			max = a[i];
//			r = i;
//		}
//	}
//	for (int i = (l > r ? r : l); i <= (l > r ? l : r); i++)
//		sum += a[i];
//	cout << sum;
//
//	return 0;
//}