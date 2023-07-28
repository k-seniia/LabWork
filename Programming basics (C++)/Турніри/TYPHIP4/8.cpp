//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//int main() {
//
//	bool p = true;
//	int n{}, x1{}, y1{}, x2{}, y2{}, x11{}, y11{}, x22{}, y22{};
//	cin >> n;
//	cin >> x1 >> y1 >> x2 >> y2;
//	for (int i = 1; i < n; i++) {
//		cin >> x11 >> y11 >> x22 >> y22;
//		if (x2 > x11 && x2 < x22 && y2 > y11 && y2 < y22) {
//			x1 = x11; y1 = y11;
//			//x2 = x2; y2 = y2;
//		}
//		else if (x1 > x11 && x1 < x22 && y1 > y11 && y1 < y22) {
//			//x1 = x1; y1 = y1;
//			x2 = x22; y2 = y22;
//		}
//		else if (x1 > x11 && x1 < x22 && y2 > y11 && y2 < y22) {
//			//x1 = x1; y2 = y2;
//			y1 = y11; x2 = x22;
//		}
//		else if (x2 > x11 && x2 < x22 && y1 > y11 && y1 < y22) {
//			x1 = x11; y2 = y22;
//			//y1 = y1; x2 = x2;
//		}
//		else {
//			cout << -1;
//			p = false;
//		}
//		
//	}
//	if (p)
//		cout << x1 << " " << y1 << " " << x2 << " " << y2;
//
//	return 0;
//}