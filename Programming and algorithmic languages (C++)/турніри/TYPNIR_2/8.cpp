//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//int main() {
//
//	int n{}, x{}, y{}; cin >> n >> x >> y;
//	int* a = new int[n];
//	cin >> a[0];
//	int d = pow(2, 16);
//	for (int i = 1; i < n; i++) {
//		a[i] = (x * a[i - 1] + y) % d;
//	}
//
//	int m{}, z{}, t{}; cin >> m >> z >> t;
//	int* b = new int[m * 2];
//	cin >> b[0];
//	d = pow(2, 30);
//	for (int i = 1; i < m * 2; i++) {
//		b[i] = (z * b[i - 1] + t) % d;
//	}
//
//	int* c = new int[m * 2];
//	for (int i = 0; i < m * 2; i++) {
//		c[i] = b[i] % n;
//	}
//
//	delete[] b;
//
//	int sum{};
//	for (int i = 0; i < m; i++) {
//		for (int j = min(c[2 * i], c[2 * i + 1]); j <= max(c[2 * i], c[2 * i + 1]); j++)
//			sum += a[j];
//	}
//
//	cout << sum;
//
//	return 0;
//}