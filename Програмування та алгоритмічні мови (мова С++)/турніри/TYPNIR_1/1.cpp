//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//	int n{}, m{}; cin >> n >> m;
//	int red{}, green{}, blue{}, black{};
//	int** tabl = new int* [n];
//	for (int i = 0; i < n; i++) {
//		tabl[i] = new int[m];
//		for (int j = 0; j < m; j++) {
//			tabl[i][j] = (i + 1) * (j + 1);
//			if (tabl[i][j] % 2 == 0 && tabl[i][j] % 3 != 0 && tabl[i][j] % 5 != 0)
//				red++;
//			if (tabl[i][j] % 3 == 0 && tabl[i][j] % 5 != 0)
//				green++;
//			if (tabl[i][j] % 5 == 0)
//				blue++;
//		}
//	}
//	black = n * m - red - green - blue;
//
//	cout << "RED\t: " << red << endl;
//	cout << "GREEN\t: " << green << endl;
//	cout << "BLUE\t: " << blue << endl;
//	cout << "BLACK\t: " << black << endl;
//
//	return 0;
//}