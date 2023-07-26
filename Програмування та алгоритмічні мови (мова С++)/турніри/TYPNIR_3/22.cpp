//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main() {
//
//	vector<int> v;
//	int N{}, i = 2; cin >> N;
//
//	bool flag = true;
//	while (v.size() != N) {
//		flag = true;
//		for (int j = 2; j <= i / 2; j++)
//			if (i % j == 0) {
//				flag = false;
//				break;
//			}
//		if (flag)
//			v.push_back(i);
//		i++;
//	}
//
//	for (auto& a : v)
//		cout << a << " ";
//
//	return 0;
//}