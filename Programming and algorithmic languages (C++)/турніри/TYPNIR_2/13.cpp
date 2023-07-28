//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main() {
//
//	int n{}; cin >> n;
//	vector<int> mas;
//
//	char ch{};
//	int i{}, j{}, x{}, min{};
//	for (int a = 0; a < n; a++) {
//		cin >> ch;
//		if (ch == '?') {
//			cin >> i >> j;
//			min = mas[i - 1];
//			for (int b = i; b < j; b++)
//				if (mas[b] < min)
//					min = mas[b];
//			cout << min << endl;
//		}
//		else if (ch == '+') {
//			cin >> i >> x;
//			mas.insert(mas.begin() + i, x);
//		}
//	}
//
//	return 0;
//}