//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//	int k{}, n{}, a[100]{}, yn[10]{}; cin >> k;
//	for (int j = 0; j < k; j++) {
//		cin >> n;
//		for (int i = 0; i < n; i++)
//			cin >> a[i];
//		for (int i = 0; i < n - 1; i++)
//			if (a[i] > 0 && a[i + 1] > 0 || a[i] < 0 && a[i + 1] < 0) {
//				yn[j] = 1;
//				break;
//			}
//	}
//	for (int j = 0; j < k; j++)
//		if (yn[j] == 1)
//			cout << "YES" << endl;
//		else
//			cout << "NO" << endl;
//
//
//	return 0;
//}