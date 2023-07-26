//#include <iostream>
//#include <thread>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <chrono>
//using namespace std;
//
//struct Student {
//	string name;
//	int score{};
//};
//
//Student find(const vector<Student>& stud, const int start, const int end) {
//	auto max = max_element(stud.begin() + start, stud.begin() + end,
//		[](const Student& s1, const Student& s2) { return s1.score < s2.score; });
//	return *max;
//}
//
//int main() {
//	srand(time(NULL));
//
//	vector<Student> stud;
//	vector<string> names = { "John", "Alice", "Bob", "Sarah", "David", "Emily", "Oliver", "Emma", "Liam", "Ava", "Jack", "Harry" };
//
//	for (int i = 0; i < names.size(); i++) {
//		stud.push_back({ names[i], rand() % 50 + 50 });
//		cout << stud[i].name << " - " << stud[i].score << endl;
//	}
//
//	int num = thread::hardware_concurrency();
//	int size = stud.size() / num;
//
//	vector<thread> threads;
//	vector<Student> max_stud(num);
//
//	for (int i = 0; i < num; ++i) {
//		int start = i * size;
//		int end = (i + 1) * size;
//		threads.emplace_back([=, &stud, &max_stud]() {max_stud[i] = find(ref(stud), start, end); });
//	}
//	for (auto& t : threads)
//		t.join();
//
//	Student max;
//	thread th([&max_stud, &max]() { max = find(ref(max_stud), 0, max_stud.size()); });
//	th.join();
//
//	cout << "\nthe student's highest score -> " << max.name << " " << max.score << endl;
//
//	return 0;
//}