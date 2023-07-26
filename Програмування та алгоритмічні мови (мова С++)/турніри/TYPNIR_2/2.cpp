//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main() {
//
//	int n{}; cin >> n;
//	string* t = new string[n], s;
//	int sizet = 0;
//	for (int i = 0; i < n; i++) {
//		cin >> t[i];
//		sizet += sizeof(t[i]);
//	}
//
//	bool flag = 1;
//	while (sizet < 1048576) {
//		getline(cin, s);
//		sizet += sizeof(s);
//		if (!s.empty())
//			for (int i = 0; i < n; i++)
//				if (s.find(t[i]) < s.size()) {
//					cout << s;
//					flag = 0;
//					break;
//				}
//		s.clear();
//	}
//	if (flag)
//		cout << -1;
//
//	delete[] t;
//	return 0;
//}