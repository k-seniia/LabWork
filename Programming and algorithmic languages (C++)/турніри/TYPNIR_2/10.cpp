//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//	int n{}, k{}; cin >> n >> k;
//
//	int* mas = new int[n] {};
//
//	char ch{};
//	int l{}, r{}, x{}, sum{};
//
//	for (int j = 0; j < k; j++) {
//		cin >> ch;
//		if (ch == 'A') {
//			cin >> l >> r >> x;
//			for (int a = l - 1; a < r; a++)
//				mas[a] = x;
//		}
//		else if (ch == 'Q') {
//			cin >> l >> r;
//			sum = 0;
//			for (int a = l - 1; a < r; a++)
//				sum += mas[a];
//			cout << sum << endl;
//		}
//	}
//
//	return 0;
//}