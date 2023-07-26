//#include <iostream>
//#include <cmath>
//#include <climits>
//
//using namespace std;
//
//int main() {
//
//	const int s = 100;
//	int n, mas[s], count{}, min = INT_MAX, min1 = INT_MAX, ii;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> mas[i];
//		if (mas[i] < min)
//			min = mas[i];
//	}
//	for (int i = 0; i < n; i++)
//		if (mas[i] < min1 && mas[i]>min) {
//			min1 = mas[i];
//			ii = i;
//		}
//	cout << min1 << " " << ++ii;
//
//	return 0;
//}