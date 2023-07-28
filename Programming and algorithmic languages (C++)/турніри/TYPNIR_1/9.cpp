//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//	int n{}, a[100]{}, l{}, r{}, sum{};
//	bool bl = 0, br = 0;
//
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//		if (a[i] < 0 && !bl) {
//			l = i;
//			bl = 1;
//		}
//		if (a[i] > 0 && !br) {
//			r = i;
//			br = 1;
//		}
//	}
//	if (br && bl)
//		for (int i = (l > r ? r : l); i <= (l > r ? l : r); i++)
//			sum += a[i];
//	else
//		for (int i = 0; i < n; i++)
//			sum += a[i];
//	cout << sum;
//
//	return 0;
//}