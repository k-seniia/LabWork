//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//	string s;
//	cin >> s;
//
//	bool flag = false;
//	int i = 1;
//	while (!flag) {
//		while (s[0] != s[i] && i < s.size())
//			i++;
//		flag = true;
//		for (int j = 0; j < s.size() - i; j++)
//			if (s[j] != s[j + i]) {
//				flag = false;
//				i++;
//				break;
//			}
//	}
//	cout << i;
//
//	return 0;
//}