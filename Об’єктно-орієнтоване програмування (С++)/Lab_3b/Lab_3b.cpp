#include <iostream>
#include "Header.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	Prepod p1("Prepod 1", 40, "mat", 2);
	Prepod p2("Prepod 2", 55, "mova", 1);
	//p1.print();
	cout << p1 << endl;


	//cout << p1.who() << endl << p1.ask() << endl;

	int mas[5] = { 5,4,2,3,4 };

	Student s1("Student 1", 18, 3, 5, 4, 5, 2);
	Student s2("Student 2", 19, mas);
	cout << s2 << endl;
	Student s3("Student 3", 20, 3, 5, 4, 5, 2);
	//s1.print();
	cout << s1 << endl;
	//s1.set_eval(2, 3, 5, 4, 5);
	//s1.print();
	//s1.set_eval(mas);
	//s1.print();

	Zav_kaf z1("ZavKaf 1", 50, "inf", 0, "pos1");
	cout << z1 << endl;

	VUZ Shtat(p1, p2, s1, s2, s3, z1);

	//cout << s1.who() << endl << s1.ask() << endl;

	cout << "\n\n\n";

	//VUZ Shtat;
	Shtat.less();
	cout << "\n\n\n";
	Shtat.debt();
	cout << "\n\n\n";
	cout << *Shtat[2];

	cout << "\n\n\n";
	Shtat[2]->print();

	Zav_kaf z2("ZavKaf 2", 45, "ist", 1, "pos2");
	Shtat.operator()(5, z2);
	cout << "\n\n\n";
	cout << *Shtat[5];

	cout << "\n\n\n\n\n";
	return 0;
}