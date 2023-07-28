//#include <iostream>
//
//using namespace std;
//
//struct TTime {
//	int Hour;
//	int Minute;
//	int Second;
//};
//
//void NextTime(TTime& Time) {
//	Time.Second++;
//	if (Time.Second == 60) {
//		Time.Second = 0;
//		Time.Minute++;
//		if (Time.Minute == 60) {
//			Time.Minute = 0;
//			Time.Hour++;
//			if (Time.Hour == 24)
//				Time.Hour = 0;
//		}
//	}
//}
//
//int main() {
//
//	TTime Time;
//	int t;
//	cin >> t; Time.Hour = t;
//	cin >> t; Time.Minute = t;
//	cin >> t; Time.Second = t;
//	NextTime(Time);
//	cout << Time.Hour << " " << Time.Minute << " " << Time.Second;
//
//	return 0;
//}