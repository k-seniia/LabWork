//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//int main() {
//
//	int n{}; cin >> n;
//	const int s = 4; int X[s], FX[s];
//	bool xfx = false; int x = n, fx{}, x1{}, fx1{}, count{};
//	while (!xfx) {
//		x--; fx++; count = 0;
//		x1 = x; fx1 = fx;
//		for (int i = 0; i < s; i++) {
//			X[i] = x1 % 10;
//			x1 /= 10;
//		}
//		for (int i = s - 1; i >= 0; i--) {
//			FX[i] = fx1 % 10;
//			fx1 /= 10;
//		}
//		for (int i = 0; i < s; i++) {
//			if (X[i] == FX[i])
//				count++;
//			else break;
//		}
//		if (count == 4) {
//			cout << x;
//			xfx = true;
//		}
//		if (fx == n) {
//			cout << 0;
//			xfx = true;
//		}
//	}
//	return 0;
//}