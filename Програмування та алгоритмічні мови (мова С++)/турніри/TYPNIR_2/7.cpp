//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//	int n{}, m{}, k{}; cin >> n >> m >> k;
//	int*** a = new int** [n];
//	for (int i = 0; i < n; i++) {
//		a[i] = new int* [m];
//		for (int j = 0; j < m; j++) {
//			a[i][j] = new int[k];
//			for (int p = 0; p < k; p++)
//				cin >> a[i][j][p];
//		}
//	}
//	cin >> k;
//	int lx{}, ly{}, lz{}, rx{}, ry{}, rz{}, sum{};
//	for (int d = 0; d < k; d++) {
//		cin >> lx >> ly >> lz >> rx >> ry >> rz;
//		for (int i = lx - 1; i < rx; i++)
//			for (int j = ly - 1; j < ry; j++)
//				for (int p = lz - 1; p < rz; p++)
//					sum += a[i][j][p];
//		cout << sum << endl;
//		sum = 0;
//	}
//
//	return 0;
//}