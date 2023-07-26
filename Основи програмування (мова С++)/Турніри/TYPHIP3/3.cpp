//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//	int a;
//
//	for (int i = 0; i < 5; i++) {
//		cin >> a;
//
//		if ((a > 999 && a < 10000 
//			&& a / 1000 % 10 != a / 100 % 10 && a / 1000 % 10 != a / 10 % 10 && a / 1000 % 10 != a % 10
//			&& a / 100 % 10 != a / 10 % 10 && a / 100 % 10 != a % 10 && a / 10 % 10 != a % 10)
//			^ (a % 10 % 3 == 0 && a % 10 != 0)
//			^ ((a > 99 && a < 1000) && (a / 10 % 10 == 0 || a % 10 == 0)))
//			cout << "YES" << endl;
//		else
//			cout << "NO" << endl;
//	}
//
//	return 0;
//}