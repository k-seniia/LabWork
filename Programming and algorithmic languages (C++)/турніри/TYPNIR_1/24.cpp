//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//	int n{}, a[100]{}, b[100]{};
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//		b[i] = i + 1;
//	}
//	for (int i = 0; i < n-1; i++)
//		for (int j = 0; j < n - i - 1; j++)
//			if (a[j] < a[j + 1]) {
//				swap(a[j], a[j + 1]);
//				swap(b[j], b[j + 1]);
//			}
//	for (int i = 0; i < n; i++)
//		cout << b[i] << " ";
//
//	return 0;
//}