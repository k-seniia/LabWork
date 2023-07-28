//#include <iostream>
//
//using namespace std;
//
//void RemovingTheSmallestDigit(int& n) {
//	if (n < 10)
//		n = 0;
//	else {
//		int mas[10], i{};
//		while (n > 0) {
//			mas[i] = n % 10;
//			n /= 10;
//			i++;
//		}
//		int min = mas[0], ind{};
//		for (int j = 1; j < i; j++)
//			if (mas[j] <= min) {
//				min = mas[j];
//				ind = j;
//			}
//		int a = 1;
//		for (int j = 0; j < i; j++)
//			if (j==ind)
//				continue;
//			else {
//				n += mas[j] * a;
//				a *= 10;
//			}
//	}
//}
//
//int main() {
//
//	int n; cin >> n;
//	RemovingTheSmallestDigit(n);
//	cout << n;
//
//	return 0;
//}