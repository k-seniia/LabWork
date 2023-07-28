//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//	int n{}, m{}; cin >> n >> m;
//	int** a = new int* [n], ** s = new int* [n];
//	for (int i = 0; i < n; i++) {
//		a[i] = new int[m];
//		s[i] = new int[m];
//		for (int j = 0; j < m; j++) {
//			cin >> a[i][j];
//			s[i][j] = 0;
//			for (int k = 0; k <= i; k++)
//				for (int t = 0; t <= j; t++)
//					s[i][j] += a[k][t];
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++)
//			cout << s[i][j] << " ";
//		cout << endl;
//	}
//
//	return 0;
//}