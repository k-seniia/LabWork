//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//	int n{}, a[20]{}, min = 10, max = 1, sum{};
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//		if (a[i] > max)
//			max = a[i];
//		if (a[i] < min)
//			min = a[i];
//	}
//	for (int i = 0; i < n; i++)
//		sum += a[i];
//	cout << sum - min - max;
//
//	return 0;
//}