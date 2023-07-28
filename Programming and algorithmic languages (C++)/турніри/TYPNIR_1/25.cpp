//#include <iostream>
//#include <math.h>
//
//using namespace std;
//
//int main() {
//
//	int k{}, a = 1, b = 1, ck{}; cin >> k;
//	long long int c{};
//
//	if (k > 5000000) {
//		a = 4971044; b = 29128; ck = 5000000;
//	}
//
//	for (int i = 1; i <= k - ck; i++) {
//		if (pow(a, 2) < pow(b, 3)) {
//			c = pow(a, 2);
//			a++;
//		}
//		else if (pow(a, 2) > pow(b, 3)) {
//			c = pow(b, 3);
//			b++;
//		}
//		else {
//			c = pow(a, 2);
//			a++; b++;
//		}
//	}
//	cout << c;
//
//	return 0;
//}