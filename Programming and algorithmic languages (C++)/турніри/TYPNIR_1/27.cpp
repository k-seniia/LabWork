//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//	int n{}, a[100][3]{};
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < 3; j++)
//			cin >> a[i][j];
//	for (int i = 0; i < n - 1; i++)
//		for (int j = 0; j < n - i - 1; j++)
//			if (a[j][0] > a[j + 1][0]) {
//				swap(a[j][0], a[j + 1][0]);
//				swap(a[j][1], a[j + 1][1]);
//				swap(a[j][2], a[j + 1][2]);
//			}
//			else if(a[j][0] == a[j + 1][0])
//				if (a[j][1] > a[j + 1][1]) {
//					swap(a[j][0], a[j + 1][0]);
//					swap(a[j][1], a[j + 1][1]);
//					swap(a[j][2], a[j + 1][2]);
//				}
//				else if(a[j][1] == a[j + 1][1])
//					if (a[j][2] > a[j + 1][2]) {
//						swap(a[j][0], a[j + 1][0]);
//						swap(a[j][1], a[j + 1][1]);
//						swap(a[j][2], a[j + 1][2]);
//					}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < 3; j++)
//			cout << a[i][j] << " ";
//		cout << endl;
//	}
//
//	return 0;
//}