//#include <iostream>
//
//using namespace std;
//
//int SumOfDigits(int n) {
//	int sum{};
//	while (n > 0) {
//		sum += n % 10;
//		n /= 10;
//	}
//	return sum;
//}
//
//int SimpleNumericalRoot(int n) {
//	bool flag = true;
//	for (int i = 2; i < n; i++)
//		if (n % i == 0) {
//			flag = false;
//			break;
//		}
//	if (flag)
//		return n;
//	else
//		if (n < 10)
//			return 0;
//		else
//			return SumOfDigits(n);
//}
//
//int main() {
//
//	int n; cin >> n;
//	cout << SimpleNumericalRoot(n);
//
//	return 0;
//}