//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//	const int s = 10;
//	int mas[s], n, mem{}, k = -1; cin >> n;
//	do {
//		k++;
//		mas[k] = n % 10;
//		n /= 10;
//	} while (n > 0);
//	for (int i = 0; i <= k; i++)
//		for (int j = 0; j <= k - 1; j++)
//			if (mas[j] > mas[j + 1]) {
//				int temp = mas[j];
//				mas[j] = mas[j + 1];
//				mas[j + 1] = temp;
//			}
//	for (int i = 0; i <= k; i++) {
//		if (i == 0) {
//			cout << mas[i] << " ";
//			mem = mas[i];
//		}
//		else if (mas[i] != mem) {
//			cout << mas[i] << " ";
//			mem = mas[i];
//		}
//	}
//
//	return 0;
//}