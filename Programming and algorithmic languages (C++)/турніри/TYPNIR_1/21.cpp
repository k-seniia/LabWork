//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//int main() {
//
//	int n{}, a[100]{}; bool flag{};
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//
//	for (int i = 1; i < n; i++) {
//		int j = i; flag = 0;
//		while (j > 0 && a[j - 1] > a[j]) {
//			swap(a[j - 1], a[j]);
//			j--;
//			flag = 1;
//		}
//		if (flag) {
//			for (int k = 0; k < n; k++)
//				cout << a[k] << " ";
//			cout << endl;
//		}
//	}
//
//	if (!flag)
//		cout << "The array is already sorted";
//	return 0;
//}