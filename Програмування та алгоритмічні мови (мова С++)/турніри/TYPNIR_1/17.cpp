//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//	int n{}, a[100]{}, max = -10000, max2 = -10000, ind{};
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//		if (a[i] > max)
//			max = a[i];
//	}
//	for (int i = 0; i < n; i++)
//		if (a[i] >= max2 && a[i] != max) {
//			max2 = a[i];
//			ind = i;
//		}
//	cout << max2 << " " << ind + 1;
//
//	return 0;
//}