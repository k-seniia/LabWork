#pragma region Includes
#include <iostream>
#include <cmath>
#include <iomanip>
#include <locale>
#include "windows.h"
#include <corecrt_math_defines.h>
using namespace std;
#pragma endregion

void task1(); void task2(); void task3(); void task4();
void task5(); void task6(); void task7(); void task8(); void task9();
void task10(); void task11(); void task12(); void task13(); void task14();

#define DEBUG
#define _USE_MATH_DEFINES

int main() {
#pragma region Ukranian
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Ukrainian");
#pragma endregion
	srand(time(NULL));

	int choise{};
	while (1) {
		cout << "choise -> "; cin >> choise;
		cout << endl;
		switch (choise) {
		case 1: task1(); break; //2.27
		case 2: task2(); break; //3.25
		case 3: task3(); break; //4.34
		case 4: task4(); break; //4.94
		case 5: task5(); break; //5.34
		case 6: task6(); break; //5.78
		case 7: task7(); break; //6.11
		case 8: task8(); break; //6.64
		case 9: task9(); break; //6.71
		case 10: task10(); break; //7.34
		case 11: task11(); break; //7.41
		case 12: task12(); break; //7.94
		case 13: task13(); break; //8.25
		case 14: task14(); break; //8.28
		case 0: return 0; break;
		default: cout << "error";
		}
		cout << endl << endl;
		system("pause");
		system("cls");
	}
	return 0;
}

void task1() {
	/*В трехзначном числе x зачеркнули первую цифру. Когда полученное число умножили на 10,
	а произведение сложили с первой цифрой числа x, то получилось число n.
	По заданному n найти число x (значение n вводится с клавиатуры, 1 ≤ n ≤ 999). */

	int n{}; cout << "n (1 <= n <= 999) = ";

#ifdef DEBUG
	n = rand() % 998 + 1; cout << n;
#else
	cin >> n;
#endif // DEBUG

	int x0 = n % 10;
	n /= 10;
	int x = x0 * 100 + n;
	cout << " -> x = " << x << endl;

}

void task2() {
	/*Вычислить значение логического выражения при всех возможных значениях логических величин А, В и С:
	а) не (А и В) и (не А или не С);
	б) не (А и не В) или (А или не С);
	в) А и не В или не (А или не С). */

	cout << boolalpha;
	for (int a = 0; a < 2; a++)
		for (int b = 0; b < 2; b++)
			for (int c = 0; c < 2; c++) {
				cout << " A -> " << (bool)a << "\tB -> " << (bool)b << "\tC -> " << (bool)c << endl;
				cout << " не (А i В) i (не А aбо не С) -> " << (!(a && b) && (!a || !c)) << endl;
				cout << " не (А i не В) або (А або не С) -> " << (!(a && !b) || (a || !c)) << endl;
				cout << " А i не В або не (А або не С) -> " << (a && !b || !(a || !c)) << endl << endl;
			}

}

void task3() {
	/*Определить, является ли число а делителем числа b? А наоборот? (Получить два ответа.) */
	cout << boolalpha;

	int a{}, b{};
#ifdef DEBUG
	a = rand() % 100; cout << "a = " << a;
	b = rand() % 100; cout << "\tb = " << b << endl;
#else
	cout << "a -> "; cin >> a;
	cout << "b -> "; cin >> b;
#endif // DEBUG

	if (a == 0 || b == 0)
		cout << "ERROR ділення на 0";
	else {
		cout << "а дільник b -> " << (b % a == 0) << endl;
		cout << "b дільник a -> " << (a % b == 0) << endl;
	}
}

void task4() {
	/*В чемпионате по футболу команде за выигрыш дается 3 очка, за проигрыш — 0, за ничью — 1.
	Известно количество очков, полученных командой за игру. 
	Определить словесный результат игры (выигрыш, проигрыш или ничья). */

	int o{}; cout << "o -> "; cin >> o;

	switch (o) {
	case 0: cout << "програш"; break;
	case 1: cout << "нічия"; break;
	case 3: cout << "виграш"; break;
	default: cout << "невірний результат";
	}

}

void task5() {
	/*Вычислить сумму 1 + 1/3 + 1/3² + ... + 1/3⁸ . Операцию возведения в степень не использовать. */

	double sum{}, n = 1;
	for (int i{}; i <= 8; i++) {
		sum += 1 / n;
		n *= 3;
	}
	cout << "sum = " << sum << endl;

}

void task6() {
	/*Вычислить приближенно площадь одной арки синусоиды.*/

	double s{}, y{};
	for (int i = 0; i <= 9; i++) {
		y = sin((M_PI / 10) * i);
		s += (M_PI / 10) * y;
	}
	cout << "Наближена площа однієї арки синусоїди = " << s;

}

void task7() {
	/*Дано число а (1 < а <= 1.5). Из чисел 1 + 1/2, 1 + 1/3, ... напечатать те, которые не меньше а*/

	double a = rand() % 1 + 1 + ((rand() % 50 + 1) / 100.0);
	int i = 2;
	while (a < 1 + 1. / i) {
		cout << "1 + 1/" << i << " = " << 1 + 1. / i << endl;
		i++;
	}
	cout << "a = " << a;
}

void task8() {
	/*Известны данные о мощности двигателя 30 моделей легковых автомобилей. 
	Выяснить, есть ли среди них модель, мощность двигателя которой превышает 200 л.с. */

	const int s = 30;
	int mas[s]{}, i{};
	for (i = 0; i < s; i++) {
		mas[i] = rand() % 200 + 100;
		if (i != 0 && i % 10 == 0)
			cout << endl;
		cout << setw(5) << mas[i];
	}
	for (i = 0; i < s; i++)
		if (mas[i] > 200) {
			cout << "\ntrue";
			break;
		}
	if (i == s)
		cout << "\nfalse";

}

void task9() {
	/*Имеется список учащихся класса с указанием роста каждого из них.
	Выяснить, перечислены ли ученики в списке в порядке убывания их роста. */

	int hp = rand() % 100 + 100, h{}, n = rand() % 10 + 10;
	cout << hp << " ";
	for (int i = 1; i < n; i++) {
		h = rand() % 100 + 100;
		cout << h << " ";
		if (h > hp) {
			cout << "false";
			break;
		}
		hp = h;
	}

}

void task10() {
	/*Даны натуральное число m и целые числа x1, x2, ..., xm.
	Определить количество чисел ix, кратных трем, и количество чисел ix, кратных семи. */

	int m = rand() % 100, x{}, count3{}, count7{};
	cout << "x = ";
	for (int i = 0; i < m; i++) {
		x = rand() % 100;
		if (x % 3 == 0)
			count3++;
		if (x % 7 == 0)
			count7++;
		if (i != 0 && i % 10 == 0)
			cout << endl << "    ";
		cout << setw(4) << x;
	}
	cout << "\n\nКількість х кратних трьом - " << count3 << endl;
	cout << "Кількість х кратних семи - " << count7 << endl;

}

void task11() {
	/*Известны оценки каждого из учеников класса по физике.
	Посчитать количество пятерок, количество четверок, количество троек и количество двоек. */

	int num{}, c5{}, c4{}, c3{}, c2{}; cout << "Введіть кількість учнів -> ";
#ifdef DEBUG
	num = rand() % 20 + 10; cout << num << endl;
#else
	cin >> num;
#endif // DEBUG

	int* mas = new int[num];
	cout << "Введіть оцінки всіх учнів -> ";
	for (int i = 0; i < num; i++) {
#ifdef DEBUG
		mas[i] = rand() % 4 + 2;
		cout << setw(3) << mas[i];
#else
		cin >> mas[i];
#endif // DEBUG
		switch (mas[i]) {
		case 2: c2++; break;
		case 3: c3++; break;
		case 4: c4++; break;
		case 5: c5++; break;
		}
	}
	cout << "\nКількість 5 -> " << c5 << endl;
	cout << "Кількість 4 -> " << c4 << endl;
	cout << "Кількість 3 -> " << c3 << endl;
	cout << "Кількість 2 -> " << c2 << endl;

	delete[] mas;
}

void task12() {
	/*Даны числа a1, a2, ..., a8. Верно ли, что их произведение меньше 10 000? */

	const int s = 8;
	int mas[s], dob = 1;
	cout << "Введіть вісім чисел -> ";
	for (int i = 0; i < s; i++) {
#ifdef DEBUG
		mas[i] = rand() % 5 + 1;
		cout << setw(3) << mas[i];
#else
		cin >> mas[i];
#endif // DEBUG
		dob *= mas[i];
	}
	if (dob < 10000)
		cout << "\nДобуток чисел = " << dob << " менший ніж 10'000";
	else
		cout << "\nДобуток чисел = " << dob << " більший ніж 10'000";

}

void task13() {
	/*Найти количество делителей каждого из целых чисел от 120 до 140.*/

	int mas[21]{};
	for (int i = 120; i <= 140; i++)
		for (int j = i; j > 0; j--)
			if (i % j == 0)
				mas[i - 120]++;
	for (int i = 120; i <= 140; i++)
		cout << "Кількість дільників у " << i << " -> " << mas[i - 120] << endl;

}

void task14() {
	/*Найти все целые числа из промежутка от 200 до 500, у которых ровно шесть делителей.*/

	int size = 301, ind{};
	int* mas = new int[size];
	for (int i = 200; i <= 500; i++) {
		int count{};
		for (int j = i; j > 0; j--)
			if (i % j == 0)
				count++;
		if (count == 6) {
			mas[ind] = i;
			ind++;
		}
	}
	cout << "Рівно шість дільників у : " << endl;
	for (int i{}; i < size; i++) {
		if (mas[i] >= 200 && mas[i] <= 500) {
			if (i != 0 && i % 8 == 0)
				cout << endl;
			cout << setw(5) << mas[i];
		}
		else break;
	}

}