#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstdio>
#include <fstream>
#include "windows.h"

using namespace std;

struct EconAct {				// Господарча діяльність
	struct {						// Товар goods
		const char* g_name;		// Назва
		int expenses;			// Видатки
		int net_profit;			// Чистий прибуток
	};
	int sales_volume;			// Об’єм продажу
	int cost;					// Собівартість реалізованого товару
	struct {						// Фірма
		const char* f_name;		// Найменування
		const char* activity;	// Вид діяльності
	};
};

void print(EconAct* gosp, int n);

int main() {
#pragma region Ukranian
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Ukrainian");
#pragma endregion
	srand(time(NULL));

	const char* tovar[] = { "телефон","магнітофон","навушники","паяльник","плеєр" };
	const char* firma[] = { "Net","Direct","Pc","Unite","Led","Jvc","Hfds","Link","Master","Media" };

	int n = rand() % 10 + 10, min_exp = INT_MAX;
	EconAct* gosp = new EconAct[n];

	for (int i = 0; i < n; i++) {
		if (i == 0)
			gosp[i].g_name = tovar[rand() % 5];
		else
			do
				gosp[i].g_name = tovar[rand() % 5];
		while (gosp[i].g_name == gosp[i - 1].g_name);
		gosp[i].expenses = (rand() % 9 + 1) * 1000;
		if (gosp[i].expenses < min_exp && gosp[i].g_name == "телефон")
			min_exp = gosp[i].expenses;
		//gosp[i].net_profit = (rand() % 20 + 1) * 1000;
		//gosp[i].f_name = firma[rand() % 10];
		//gosp[i].activity = "електроніка";
	}

	print(gosp, n);

	for (int i = 0; i < n; i++)
		if (gosp[i].expenses == min_exp && gosp[i].g_name == "телефон")
			cout //<< "\n Найменування фірми - " << gosp[i].f_name << "\n Вид діяльності - " << gosp[i].activity
			<< "\n Назва товару - " << gosp[i].g_name << "\n Видатки - " << gosp[i].expenses << endl;

	cout << endl << endl << endl;
	return 0;
}

void print(EconAct* gosp, int n) {
	if (n % 2 == 0)
		for (int i = 0; i < n;) {
			/*cout << " Найменування фірми - " << gosp[i++].f_name << "\t Найменування фірми - " << gosp[i].f_name << endl;
			i--;
			cout << " Вид діяльності - " << gosp[i++].activity << "\t Вид діяльності - " << gosp[i].activity << endl;
			i--;*/
			if (strlen(gosp[i].g_name) < 8)
				cout << " Назва товару - " << gosp[i].g_name << "\t\t Назва товару - " << gosp[i + 1].g_name << endl;
			else
				cout << " Назва товару - " << gosp[i].g_name << "\t Назва товару - " << gosp[i + 1].g_name << endl;
			cout << " Видатки - " << gosp[i].expenses << "\t\t\t Видатки - " << gosp[i + 1].expenses << endl;
			i += 2;
			cout << endl;
		}
	else {
		for (int i = 0; i < n - 1;) {
			/*cout << " Найменування фірми - " << gosp[i++].f_name << "\t Найменування фірми - " << gosp[i].f_name << endl;
			i--;
			cout << " Вид діяльності - " << gosp[i++].activity << "\t Вид діяльності - " << gosp[i].activity << endl;
			i--;*/
			if (strlen(gosp[i].g_name) < 8)
				cout << " Назва товару - " << gosp[i].g_name << "\t\t Назва товару - " << gosp[i + 1].g_name << endl;
			else
				cout << " Назва товару - " << gosp[i].g_name << "\t Назва товару - " << gosp[i + 1].g_name << endl;
			cout << " Видатки - " << gosp[i].expenses << "\t\t\t Видатки - " << gosp[i + 1].expenses << endl;
			i += 2;
			cout << endl;
		}
		/*cout << " Найменування фірми - " << gosp[n - 1].f_name << endl;
		cout << " Вид діяльності - " << gosp[n - 1].activity << endl;*/
		cout << " Назва товару - " << gosp[n - 1].g_name << endl;
		cout << " Видатки - " << gosp[n - 1].expenses << endl;
		cout << endl << endl;
	}
}