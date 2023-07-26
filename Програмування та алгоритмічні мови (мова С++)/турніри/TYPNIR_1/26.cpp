//#include <iostream>
//#include <math.h>
//
//using namespace std;
//
//int main() {
//
//	int n{}, a[100]{}, el1{}, el2{};
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	for (int i = 0; i < n - 1; i++)
//		for (int j = 0; j < n - i - 1; j++) {
//			el1 = abs(a[j] % 10 + a[j] / 10 % 10 + a[j] / 100 % 10 + a[j] / 1000 % 10);
//			el2 = abs(a[j + 1] % 10 + a[j + 1] / 10 % 10 + a[j + 1] / 100 % 10 + a[j + 1] / 1000 % 10);
//			if (el1 > el2)
//				swap(a[j], a[j + 1]);
//			else if (el1 == el2)
//				if (a[j] > a[j + 1])
//					swap(a[j], a[j + 1]);
//		}
//	for (int i = 0; i < n; i++)
//		cout << a[i] << " ";
//
//	return 0;
//}