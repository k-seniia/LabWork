#pragma region Includes
#include <iostream>
#include <math.h>
#include <iomanip>
#include <locale>
#include "windows.h"
using namespace std;
#pragma endregion

//#define DEBUG

void task1(); void task2();

int main() {
#pragma region Ukranian
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Ukrainian");
#pragma endregion
	//cout << setprecision(5);
	bool flag = true;
	while (flag) {
		int choise{};
		cout << "Оберіть завдання із запропонованого меню:" << endl;
		cout << "1 - Завдання 1" << endl;
		cout << "2 - Завдання 2" << endl;
		cout << "0 - Вихід із програми" << endl;
		cout << "Ваш вибір -> "; cin >> choise; cout << endl;

		switch (choise) {
		case 0: flag = false; break;
		case 1: task1(); break;
		case 2: task2(); break;
		default: cout << "Невірний вибір, натисніть ENTER та оберіть знову" << endl; break;
		}
		cout << endl << endl;
		system("pause");
		system("cls");
	}

	return EXIT_SUCCESS;
}

void task1() {
	const double X = 0.8;
	const int N = 7;
	double s = X, a1 = X, q{}, a2{};
	
	cout << " i = " << 0 << "\ta1 = " << a1 << "\tS = " << s << endl;
	
	for (int i = 1; i <= N; i++) {
		q = (pow(X, 4) * (4 * (i - 1) + 1)) / (4 * (i - 1) + 5);
		a2 = a1 * q;
		s += a2; //s += pow(X, 4 * i + 1) / (4 * i + 1);
		a1 = a2;
		cout << " i = " << i <<"\tS = " << s << endl;
	}
	cout << "\tS = " << s << endl;
}

void task2() {
	const double EPS = 1E-5, hx = 0.1;
	double s{}, a1{}, a2{}, q{};
	int i{};

	for (double x = 0.1; x <= 0.8; x += hx) {
		s = x; i = 1; a1 = x;
		do {
			q = (pow(x, 4) * (4 * (i - 1) + 1)) / (4 * (i - 1) + 5);
			a2 = a1 * q;
			s += a2;
			a1 = a2;
			i++;
		} while (a2 > EPS);
		cout << " x = " << x << "    i = " << i << "\ta = " << a2 << "\t  S = " << s << endl;
	}
}