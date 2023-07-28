//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//int main() {
//
//	int n{}, m{}, x{};
//	cin >> n >> m >> x;
//	int* p = new int[n] {}, count{};
//	string s;
//	for (int i = 0; i < n; i++) {
//		cin >> s;
//		for (int j = 0; s[j]; j++)
//			p[i] += ((int)s[j] - 48) * pow(x, j);
//		p[i] %= m;
//		for (int j = 0; j < i; j++)
//			if (p[i] == p[j])
//				count++;
//	}
//	cout << count;
//
//	return 0;
//}