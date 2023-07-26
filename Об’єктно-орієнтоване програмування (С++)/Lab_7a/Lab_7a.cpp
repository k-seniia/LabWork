#include <iostream>
#include <fstream>
#include "Header.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	
	string s, s1;
	cin >> s;
	TEXT t(s), t1("0");

	//try {
	//	ofstream f("text.txt");
	//	if (!f) throw "‘айл в≥дсутн≥й";
	//	f << t;
	//	f.close();
	//	
	//	ifstream f1("text.txt");
	//	if (!f) throw "‘айл в≥дсутн≥й";
	//	f1 >> s1;
	//	cout << s1 << endl;
	//	//f1 >> t1;
	//	//t1.show();
	//	f1.close();
	//}
	//catch (string s) { cout << s << endl; }

	try {
		fstream f("text.txt", ios::out | ios::in);
		if (!f) throw "‘айл в≥дсутн≥й";
		f << t;
		f >> s1;
		cout << s1 << endl;
		//f1 >> t1;
		//t1.show();
		f.close();
	}
	catch (string s) { cout << s << endl; }

	cout << "\n\n\n\n\n";
	return 0;
}