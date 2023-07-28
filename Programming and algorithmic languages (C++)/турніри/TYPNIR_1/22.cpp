//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//	int n{}, a[1000]{}, count{}, ind{}, min{};
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	for (int i = 0; i < n; i++) {
//		min = i;
//		for (int j = i + 1; j < n; j++)
//			min = (a[j] < a[min] ? j:min);
//		if (i != min) {
//			swap(a[i], a[min]);
//			if (i == ind) {
//				count++;
//				ind = min;
//			}
//			else if (min == ind) {
//				count++;
//				ind = i;
//			}
//		}
//	}
//	cout << count;
//
//	return 0;
//}