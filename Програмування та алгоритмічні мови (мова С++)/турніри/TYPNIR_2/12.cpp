//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//int main() {
//
//	vector<int> mas;
//
//	int k{}; cin >> k;
//	string func{}, num{};
//	for (int i = 0; i < k; i++) {
//		cin >> func;
//		if (func == "GetMin") {
//			auto min = min_element(mas.begin(), mas.end());
//			cout << *min << endl;
//			mas.erase(min);
//		}
//		else if (func == "GetMax") {
//			auto max = max_element(mas.begin(), mas.end());
//			cout << *max << endl;
//			mas.erase(max);
//		}
//		else if (func[0] == 'I') {
//			num = func.substr(7, func.size() - 8);
//			mas.push_back(stoi(num));
//		}
//	}
//	return 0;
//}