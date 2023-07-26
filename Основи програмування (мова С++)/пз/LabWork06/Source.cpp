#pragma region Includes
#include <iostream>
#include <math.h>
#include <iomanip>
#include <locale>
#include "windows.h"
using namespace std;
#pragma endregion

void task1(); void task2(); void task3(); void task4();

//#define DEBUG

int main() {
#pragma region Ukranian
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Ukrainian");
#pragma endregion
	srand(time(NULL));
	cout << setprecision(3);

	while (1) {
		int choise{};
		cout << "Оберіть завдання із запропонованого меню:" << endl;
		cout << "1 - Завдання 1" << endl;
		cout << "2 - Завдання 2" << endl;
		cout << "3 - Завдання 3" << endl;
		cout << "4 - Завдання 4" << endl;
		cout << "0 - Вихід із програми" << endl;
		cout << "Ваш вибір -> "; cin >> choise; cout << endl;

		switch (choise) {
		case 0: return 0; break;
		case 1: task1(); break;
		case 2: task2(); break;
		case 3: task3(); break;
		case 4: task4(); break;
		default: cout << "Невірний вибір, натисніть ENTER та оберіть знову" << endl; break;
		}
		cout << endl << endl;
		system("pause");
		system("cls");
	}
	
	system("pause");
	return EXIT_SUCCESS;
}

void task1() {
	double a{}, x{};
#ifdef DEBUG
	cout << "Введіть x -> "; cin >> x;
	cout << "Введіть a -> "; cin >> a;
#else
	cout << "x -> "; x = rand() % 100 / (double)10 - 5; cout << x << endl;
	cout << "a -> "; a = rand() % 100 / (double)10 - 5; cout << a << endl;
#endif // DEBUG

	if (x < a) {
		if (pow(cbrt(a * a) - cbrt(x * x), 3) >= 0)
			cout << "Y = " << -sqrt(pow(cbrt(a * a) - cbrt(x * x), 3)) << endl;
		else
			cout << "ERROR - область визначення квадратного кореня -> x>=0" << endl;
	}
	else if (x >= a) {
		if (x > 0)
			cout << "Y = " << log(x) << endl;
		else
			cout << "ERROR - область визначення ln(x) -> x>0" << endl;
	}
}

void task2() {
	double a{}, x{};
#ifdef DEBUG
	cout << "Введіть x -> "; cin >> x;
	cout << "Введіть a -> "; cin >> a;
#else
	cout << "x -> "; x = rand() % 100 / (double)10 - 5; cout << x << endl;
	cout << "a -> "; a = rand() % 45 / (double)10; cout << a << endl;
#endif // DEBUG

	switch ((int)a) {
	case 0: cout << "y = " << 2 * tan(x) - pow(x, 3) << endl;	break;
	case 1: 
		if (x > 0)
			cout << "y = " << log10(x) + x << endl;
		else
			cout << "ERROR - область визначення log(x) -> x>0" << endl;
		break;
	case 2: cout << "y = " << (x * x - 1) / 6 << endl; break;
	case 3: cout << "y = " << pow(x, 3) + x - 1 << endl; break;
	default: cout << "Невірне введення" << endl; break;
	}
}

void task3() {
	double x{}, y{};
#ifdef DEBUG
		cout << "Введіть x -> "; cin >> x;
		cout << "Введіть y -> "; cin >> y;
#else
		cout << "x -> "; x = rand() % 41 / (double)10 - 2.5; cout << x << endl;
		cout << "y -> "; y = rand() % 41 / (double)10 - 2.5; cout << y << endl;
#endif // DEBUG

		if (y <= 1 && y >= -1 && x <= 1 && x >= -1) {
			if(y == 1 || y == -1 || x == 1 || x == -1)
				cout << "Точка (" << x << "," << y << ") - лежить на межі заданої області" << endl;
			else
				cout << "Точка (" << x << "," << y << ") - належить до заданої області" << endl;
		}
		else if (y <= 0 && y >= -2 && x <= 0 && x >= -2) {
			if (y == 0 || y == -2 || x == 0 || x == -2)
				cout << "Точка (" << x << "," << y << ") - лежить на межі заданої області" << endl;
			else
				cout << "Точка (" << x << "," << y << ") - належить до заданої області" << endl;
		}
		else
			cout << "Точка (" << x << "," << y << ") - не належить до заданої області" << endl;
}

void task4() {
	double a{}, x{}, b{};
#ifdef DEBUG
	cout << "x -> "; cin >> x;
	cout << "a -> "; cin >> a;
	cout << "b -> "; cin >> b;
#else
	cout << "x -> "; x = rand() % 100 / (double)10 - 5; cout << x << endl;
	cout << "a -> "; a = rand() % 100 / (double)10 - 5; cout << a << endl;
	cout << "b -> "; b = rand() % 100 / (double)10 - 5; cout << b << endl;
#endif // DEBUG

	if (pow(x, 5) + 1.25 * 1e-2 * sin(pow(b, 2)) + cbrt(a + 0.6) == 0)
		cout << "ERROR - знаменник дорівнює 0" << endl;
	else if (pow(x + 1, 2) <= 0)
		cout << "ERROR - область визначення log(x) -> x>0" << endl;
	else
		cout << "y = " << (log10(pow(x + 1, 2)) + 1.5 * pow(x, 3) + cbrt(x + 0.6 * 1e3))
														/
							(pow(x, 5) + 1.25 * 1e-2 * sin(pow(b, 2)) + cbrt(a + 0.6)) << endl;
}