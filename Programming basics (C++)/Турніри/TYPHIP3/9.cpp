//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//int main() {
//
//	int a, mas[3];
//	cin >> a;
//	for (int i = 0; i < 3; i++) {
//		mas[i] = a / pow(10, 2 - i);
//		mas[i] %= 10;
//	}
//	for (int i = 0; i < 3; i++)
//		for (int j = 0; j < 3 - i - 1; j++)
//			if (mas[j] < mas[j + 1]) {
//				int temp = mas[j];
//				mas[j] = mas[j + 1];
//				mas[j + 1] = temp;
//			}
//	for (int i = 0; i < 3; i++)
//		cout << mas[i];
//
//	return 0;
//}