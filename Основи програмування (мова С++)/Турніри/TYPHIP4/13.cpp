//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//int main() {
//
//	const int s = 10;
//	int a[s], x, y, temp; cin >> x >> y;
//	a[0] = x; a[1] = y;
//	for (int i = 2; i < s; i++)
//		a[i] = a[i - 1] + a[i - 2];
//	for (int i = 0; i < s/2; i++) {
//		temp = a[i];
//		a[i] = a[s - i - 1];
//		a[s - i - 1] = temp;
//	}
//	for (int i = 0; i < s; i++)
//		cout << a[i] << " ";
//
//	return 0;
//}