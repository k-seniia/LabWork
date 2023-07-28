//#include <iostream>
//using namespace std;
//int main() {
//	int n;
//	cin >> n;
//	int mas[5];
//	for (int i = 0; i < 5; i++) {
//		int r = pow(10, 4 - i);
//		mas[i] = n / r % 10;
//	}
//	for (int i = 0; i < 5/2; i++) {
//		int temp = mas[i];
//		mas[i] = mas[5 - 1 - i];
//		mas[5 - 1 - i] = temp;
//	}
//	n = 0;
//	for (int i = 0; i < 5; i++) {
//		int r = pow(10, 4 - i);
//		n += mas[i] * r;
//	}
//	cout << n;
//	return 0;
//}