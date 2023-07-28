//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//int main() {
//
//	const int s = 1000;
//	int n, mas[s], temp; cin >> n;
//	for (int i = 0; i < n; i++)
//		cin >> mas[i];
//	for (int i = 0; i < n - 1; i++)
//		for (int j = 0; j < n - i - 1; j++)
//			if (mas[j] > mas[j + 1]) {
//				temp = mas[j];
//				mas[j] = mas[j + 1];
//				mas[j + 1] = temp;
//			}
//	for (int k = 0; k < n; k++)
//		cout << mas[k] << " ";
//
//	return 0;
//}