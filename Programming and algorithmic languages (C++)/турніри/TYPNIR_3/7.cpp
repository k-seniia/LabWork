//#include <iostream>
//
//using namespace std;
//
//struct TDate {
//	int Day;
//	int Month;
//	int Year;
//};
//
//bool IsTheDateCorrect(TDate Date) {
//	if (Date.Year < 1582 || (Date.Year == 1582 && (Date.Month < 10 || (Date.Month == 10 && Date.Day < 15))))
//		return false;
//	if (Date.Month < 1 || Date.Month > 12)
//		return false;
//	if (Date.Day < 1 || Date.Day > 31)
//		return false;
//	if (Date.Month == 2 && Date.Day > 29)
//		return false;
//	if (Date.Month == 4 || Date.Month == 6 || Date.Month == 9 || Date.Month == 11)
//		if (Date.Day > 30)
//			return false;
//	return true;
//}
//
//int main() {
//
//	TDate Date;
//	int d;
//	cin >> d; Date.Day = d;
//	cin >> d; Date.Month = d;
//	cin >> d; Date.Year = d;
//	cout << boolalpha << IsTheDateCorrect(Date);
//
//	return 0;
//}