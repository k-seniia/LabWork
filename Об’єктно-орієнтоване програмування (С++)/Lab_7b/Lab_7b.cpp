#include <iostream>
#include <fstream>
#include <iomanip>
#include "Header.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	const int n = 10;
	int mas[n], mas2[n], x, b = 77, a = 88;
	for (int i = 0; i < n; i++) {
		mas[i] = rand() % 100;
		cout << setw(4) << mas[i];
	}
	try {
		fstream f("bin.txt", ios::binary | ios::in | ios::out);
		if (!f) throw "Ôàéë â³äñóòí³é";
		f.write((char*)mas, sizeof(mas));

		f.seekg(4 * sizeof(int), ios::beg);
		f.read((char*)&x, sizeof(int));
		cout << endl << "x = " << x << endl;

		if (x % 2 == 0)
			for (int i = 0; i < 4; i++) {
				f.seekp(i * sizeof(int), ios::beg);
				f.write((char*)&b, sizeof(int));
			}
		else
			for (int i = 5; i < n; i++) {
				f.seekp(i * sizeof(int), ios::beg);
				f.write((char*)&a, sizeof(int));
			}

		f.seekg(0, ios::beg);
		f.read((char*)mas2, sizeof mas2);
		for (int i = 0; i < 10; i++)
			cout << setw(4) << mas2[i];

		f.close();
	}
	catch (string s) { cout << s << endl; }

	cout << "\n\n\n\n\n";
	return 0;
}