//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//	int n{}, count{}; cin >> n;
//	bool flag = true;
//	do {
//		flag = true;
//		for (int i = 2; i < n; i++)
//			if (n % i == 0)
//				flag = false;
//		if (flag && n != 1)
//			count++;
//		cin >> n;
//	} while (n != 0);
//	cout << count;
//
//	return 0;
//}