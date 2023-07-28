//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int gcd(int a, int b) {
//	if (b == 0) return a;
//	return gcd(b, a % b);
//}
//
//int main() {
//
//	int n{};
//	cin >> n;
//	vector<int> v;
//	while (n != 0) {
//		v.push_back(n);
//		cin >> n;
//	}
//
//	int r = v[0];
//	for (int i=1;i<v.size();i++) {
//		r = gcd(r, v[i]);
//	}
//	cout << r;
//
//	return 0;
//}