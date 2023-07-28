#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	const int t = 9; //	"\t"=setw(9)

	cout << "Лабораторна робота №4 ст. гр. wkitb.de Гетьман Ксенiї\n";
	
	cout << "\nВведiть три цiлих числа через enter\n\n";
	int a;	cout << "a=";	cin >> a;
	int b;	cout << "b=";	cin >> b;
	int c;	cout << "c=";	cin >> c;
	cout << setw(5 * t + 27) << "Цiлi числа (ширина поля рiвна 6)\n";
	cout << setw(2 * t + 19) << "Виведення без формату" << setw(4 * t + 20) << "Виведення по формату\n";
	cout << setw(2 * t + 4) << "a=" << a << setw(6 * t) << "a=" << setw(6) << a << endl;
	cout << setw(2 * t + 4) << "b=" << b << setw(6 * t) << "b=" << setw(6) << b << endl;
	cout << setw(2 * t + 4) << "c=" << c << setw(6 * t) << "c=" << setw(6) << c << endl;
	cout << "\n\t\tУ вiсiмковому форматi" << setw(4 * t + 26) << "У шiстнадцятковому форматi\n";
	cout << setw(2 * t + 4) << "a=" << showbase << oct << a << setw(6 * t - 1) << "a=" << showbase << hex << a << endl;
	cout << setw(2 * t + 4) << "b=" << showbase << oct << b << setw(6 * t - 1) << "b=" << showbase << hex << b << endl;
	cout << setw(2 * t + 4) << "c=" << showbase << oct << c << setw(6 * t - 1) << "c=" << showbase << hex << c << endl;

	cout << "\nВведiть два дiйсних числа через enter\n\n";
	float d;	cout << "d=";	cin >> d;
	float e;	cout << "e=";	cin >> e;
	cout << setw(4 * t + 37) << "Дiйснi числа (ширина поля рiвна 7.3)\n";
	cout << "\tВиведення без формату\t\tВиведення з фiксов. крапкою\t\tВиведення з плаваючою крапкою\n";
	cout << setw(t + 4) << "d=" << d << setw(3 * t + 2) << "d=" << setw(7) << fixed << setprecision(3) 
		 << d << setw(4 * t - 3) << "d=" << scientific << d << defaultfloat << endl;
	cout << setw(t + 4) << "e=" << e << setw(3 * t + 2) << "e=" << setw(7) << fixed << setprecision(3) 
		 << e << setw(4 * t - 3) << "e=" << scientific << e << defaultfloat << endl;

	cout << "\nВведiть символ через enter\n\n";
	char f;	cout << "f=";	cin >> f;
	cout << setw(5 * t + 29) << "Символьнi данi (ширина поля рiвна 5)\n";
	cout << setw(2 * t + 19) << "Виведення без формату" << setw(4 * t + 20) << "Виведення по формату\n";
	cout << setw(2 * t + 4) << "f=" << f << setw(6 * t + 3) << "f = " << setw(5) << f << endl;

	cout << "\nВведiть 0(false) або 1(true) через enter\n\n";
	bool g;	cout << "boolean=";	cin >> g;
	cout << setw(4 * t + 33) << "Логiчнi данi (ширина поля рiвна 5)\n";
	cout << "\tВиведення без формату\t\tВиведення по формату\t\tТекстове виведення\n";
	cout << setw(t * 2 + 2) << "boolean=" << g << setw(3 * t + 4) << "boolean=" << setw(5) 
		 << g << setw(3 * t) << "boolean=" << boolalpha << g << endl;

	cout << endl << endl;
	system("pause");
	return EXIT_SUCCESS;
}