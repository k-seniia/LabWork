//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//	int n{}, v[100]{}, p[100]{};
//	double max{};
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		cin >> v[i];
//	for (int i = 0; i < n; i++) {
//		cin >> p[i];
//		if (v[i] / 100. * p[i] > max)
//			max = v[i] / 100. * p[i];
//	}
//	for (int i = 0; i < n; i++)
//		if (v[i] / 100. * p[i] == max) {
//			cout << i + 1;
//			break;
//		}
//
//	return 0;
//}