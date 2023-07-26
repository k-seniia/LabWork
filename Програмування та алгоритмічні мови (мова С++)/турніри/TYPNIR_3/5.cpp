//#include <iostream>
//
//using namespace std;
//
//bool IsPalindrom(int n) {
//	bool b = 1;
//	int mas[9], i{};
//	while (n > 0) {
//		mas[i] = n % 10;
//		n /= 10;
//		i++;
//	}
//	for (int j = 0; j < i / 2; j++)
//		if (mas[j] != mas[i - j - 1])
//			b = 0;
//	return b;
//}
//
//int main() {
//
//	int n; cin >> n;
//	cout << boolalpha << IsPalindrom(n);
//
//	return 0;
//}