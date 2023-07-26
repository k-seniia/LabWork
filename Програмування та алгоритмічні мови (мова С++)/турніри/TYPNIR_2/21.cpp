//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int main() {
//
//	string s, buf; cin >> s;
//	vector<string> v;
//	bool flag = true;
//	for (int i = 0; i < s.size(); i++)
//		for (int j = 0; j < s.size(); j++) {
//			flag = true;
//			buf = s.substr(i, j);
//			for (auto& a : v)
//				if (buf == a)
//					flag = false;
//			if (flag)
//				v.push_back(buf);
//		}
//	cout << v.size();
//	return 0;
//}