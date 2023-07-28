//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//	int n{}, m{}; cin >> n >> m;
//	int** a = new int* [n];
//	for (int i = 0; i < n; i++) {
//		a[i] = new int[m];
//		for (int j = 0; j < m; j++)
//			cin >> a[i][j];
//	}
//	int k{}; cin >> k;
//	int lx{}, ly{}, rx{}, ry{}, sum{};
//	for (int p = 0; p < k; p++) {
//		cin >> lx >> ly >> rx >> ry;
//		for (int i = lx - 1; i < rx; i++)
//			for (int j = ly - 1; j < ry; j++)
//				sum += a[i][j];
//		cout << sum << endl;
//		sum = 0;
//	}
//
//	return 0;
//}