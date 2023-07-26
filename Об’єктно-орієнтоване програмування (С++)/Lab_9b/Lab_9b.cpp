#include <iostream>
#include <iomanip>
#include "Header.h"
#include <map>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	//srand(time(NULL));

	string names[5] = { "Young", "White", "Tran", "Thompson", "Smith" };
	int ages[5] = { 29,49,32,38,47 };
	int count = 0;

	map <PERSON, int> m1;
	map <PERSON, int, PERSON> m2;


	for (int i = 0; i < 5; i++) {
		m1.insert({ PERSON(names[i],ages[i]), ++count });
		//m1.insert({ (PERSON(names[i]), PERSON(ages[i])), ++count });
	}
	cout << endl;
	for (const auto& x : m1) {
		cout << x.first.get_name() << " " << x.first.get_age() << " " << x.second;
	}
	cout << endl;
	for (int i = 0; i < 5; i++) {
		m2.insert({ PERSON(names[i],ages[i]), ++count });
		//m1.insert({ (PERSON(names[i]), PERSON(ages[i])), ++count });
	}
	cout<< endl;
	for (const auto& x : m2) {
		cout << x.first.get_name() << " " << x.first.get_age() << " " << x.second;
	}


	
//{
//		map<int, int>m3;
//		m3.insert(1, 2);
//	}

	cout << "\n\n\n\n\n";
	return 0;
}