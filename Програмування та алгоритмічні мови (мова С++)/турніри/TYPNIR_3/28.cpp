//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//	int a{}, b{};
//	bool flag{};
//	cin >> a >> b;
//	for (int i = a < b ? a : b; i > 0; i--) {
//		if (a % i == 0 && b % i == 0 && i % 2 == 0) {
//			cout << i << " ";
//			break;
//		}
//		if (i == 1)
//			cout << 0 << " ";
//	}
//	for (int i = a < b ? a : b; i > 0; i--) {
//		if (a % i == 0 && b % i == 0 && i % 2 != 0) {
//			cout << i << " ";
//			break;
//		}
//		if (i == 1)
//			cout << 0 << " ";
//	}
//
//	return 0;
//}