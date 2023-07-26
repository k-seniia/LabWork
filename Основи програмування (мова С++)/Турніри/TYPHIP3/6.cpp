//#include <iostream>
//#include <cmath>
//using namespace std;
//
//void swap(int* a, int* b) {
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//int main() {
//
//	int a, mas[4];
//	cin >> a;
//	for (int i = 0; i < 4; i++) {
//		mas[i] = a / pow(10,3-i);
//		mas[i] %= 10;
//	}
//	for (int i = 0; i < 4; i++)
//		for (int j = 0; j < 4 - i - 1; j++) {
//			if (mas[j] == 0)
//				int a = 1;
//			else
//				if (mas[j] > mas[j + 1])
//					swap(mas[j], mas[j + 1]);
//		}
//		if (mas[0] == 0) {
//			if (mas[1] > 0)
//				swap(mas[0], mas[1]);
//			else if (mas[1] == 0) {
//				if (mas[2] == 0)
//					swap(mas[0], mas[3]);
//				else if (mas[2] > 0)
//					swap(mas[0], mas[2]);
//			}
//		}
//	for (int i = 0; i < 4; i++)
//		cout << mas[i];
//
//	return 0;
//}