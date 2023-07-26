//#include <iostream>
//
//using namespace std;
//
//bool IsTheSameSetOfDigits(int A, int B) {
//	bool vA[10]{}, vB[10]{};
//	while (A > 0) {
//		vA[A % 10] = true;
//		A /= 10;
//	}
//	while (B > 0) {
//		vB[B % 10] = true;
//		B /= 10;
//	}
//	for (int i = 0; i < 10; i++)
//		if (vA[i] != vB[i])
//			return false;
//	return true;
//}
//
//int main() {
//
//	int A, B;
//	cin >> A >> B;
//	cout << boolalpha << IsTheSameSetOfDigits(A, B);
//
//	return 0;
//}