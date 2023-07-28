//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//	int n{}, a[200]{}, x{};
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	cin >> x;
//
//	for (int i = 0; i < n-1; i++)
//		for (int j = 0; j < n - i - 1; j++)
//			if (a[j] < a[j + 1])
//				swap(a[j], a[j + 1]);
//
//	int i = -1;
//	do
//		i++;
//	while (!(a[i] < x) && i < n);
//	cout << i + 1;
//
//	return 0;
//}