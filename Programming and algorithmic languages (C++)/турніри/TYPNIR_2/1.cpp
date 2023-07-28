//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//	int n{}, m{};
//	cin >> n >> m;
//	int* mas = new int[n];
//	for (int i = 0; i < n; i++)
//		cin >> mas[i];
//
//	bool flag = 1;
//	if (n % 2 == 0) {
//		for (int i = 0; i < n / 2; i++)
//			if (mas[i] != mas[n - i - 1])
//				flag = 0;
//		if (flag)
//			cout << n / 2 << " ";
//	}
//	for (int i = n / 2; i >= 0; i--)
//		if (mas[i] == mas[i + 1]) {
//			flag = 1;
//			for (int j = 0; j <= i; j++)
//				if (mas[j] != mas[i + j])
//					flag = 0;
//			if (flag)
//				cout << n - i - 1 << " ";
//		}
//	cout << n;
//
//	delete[] mas;
//	return 0;
//}