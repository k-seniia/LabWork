//#include <iostream>
//#include <cmath>
//#include <climits>
//
//using namespace std;
//
//int main() {
//
//	const int s = 100;
//	int n, mas[s], count{}, min = INT_MAX, max = INT_MIN, l, r;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> mas[i];
//		if (mas[i] >= max) {
//			max = mas[i];
//			r = i;
//		}
//		if (mas[i] < min) {
//			min = mas[i];
//			l = i;
//		}
//	}
//	for (int i = ((l < r) ? l : r); i <= ((l < r) ? r : l); i++)
//		if (mas[i] < 0)
//			count++;
//	cout << count;
//
//	return 0;
//}