//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//	int n{}; cin >> n;
//	int* a = new int[n];
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	int k{}, l{}, r{}, min{}; cin >> k;
//	for (int i = 0; i < k; i++) {
//		cin >> l >> r;
//		min = a[l - 1];
//		for (int j = l; j < r; j++)
//			if (a[j] < min)
//				min = a[j];
//		cout << min << endl;
//	}
//
//	return 0;
//}