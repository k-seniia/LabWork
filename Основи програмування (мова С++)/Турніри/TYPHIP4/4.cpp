//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//int main() {
//
//	const int s = 10000;
//	int mas[s]{}, lm[s / 2]{}, count = -1, max{}, i = -1;
//	do {
//		i++;
//		cin >> mas[i];
//	} while (mas[i] != 0);
//	for (int j = 1; j < i - 1; j++)
//		if (mas[j] > mas[j - 1] && mas[j] > mas[j + 1]) {
//			count++;
//			lm[count] = j;
//		}
//	if (lm[0] == 0 && lm[1] == 0)
//		cout << 0;
//	else {
//		for (int j = 0; j < count; j++)
//			if (abs(lm[j] - lm[j + 1]) > max)
//				max = abs(lm[j] - lm[j + 1]) - 1;
//		cout << max;
//	}
//
//	return 0;
//}