//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//	int mas[4];
//	for (int i = 0; i < 4; i++) {
//		cin >> mas[i];
//	}
//	for (int i = 0; i < 4; i++)
//		for (int j = 0; j < 4 - i - 1; j++)
//			if (mas[j] < mas[j + 1]) {
//				int temp = mas[j];
//				mas[j] = mas[j + 1];
//				mas[j + 1] = temp;
//			}
//	for (int i = 0; i < 4; i++)
//		cout << mas[i] << " ";
//
//	return 0;
//}