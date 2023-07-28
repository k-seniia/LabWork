//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//	string s; cin >> s;
//	bool flag = true;
//	for (int i = 0; i < s.size() / 2; i++)
//		if (s[i] != s[s.size() - 1 - i])
//			flag = false;
//	int count{};
//	if (flag) {
//		bool flagp = false;
//		for (int j = 0, i = 0; j < s.size(); j++) {
//			flagp = false;
//			if (i < j){
//				for (int k = i; k <= j / 2; k++) {
//					flagp = false;
//					if (s[k] != s[j - k])
//						break;
//					flagp = true;
//				}
//				if (flagp) {
//					count++;
//					i++; j--;
//				}
//			}
//		}
//	}
//	cout << count;
//
//	return 0;
//}