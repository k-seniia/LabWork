#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstdio>
#include <fstream>
#include "windows.h"

using namespace std;

struct EconAct {				// ���������� ��������
	struct {						// ����� goods
		const char* g_name;		// �����
		int expenses;			// �������
		int net_profit;			// ������ ��������
	};
	int sales_volume;			// �ᒺ� �������
	int cost;					// ���������� ������������ ������
	struct {						// Գ���
		const char* f_name;		// ������������
		const char* activity;	// ��� ��������
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

	const char* tovar[] = { "�������","���������","���������","��������","����" };
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
		if (gosp[i].expenses < min_exp && gosp[i].g_name == "�������")
			min_exp = gosp[i].expenses;
		//gosp[i].net_profit = (rand() % 20 + 1) * 1000;
		//gosp[i].f_name = firma[rand() % 10];
		//gosp[i].activity = "����������";
	}

	print(gosp, n);

	for (int i = 0; i < n; i++)
		if (gosp[i].expenses == min_exp && gosp[i].g_name == "�������")
			cout //<< "\n ������������ ����� - " << gosp[i].f_name << "\n ��� �������� - " << gosp[i].activity
			<< "\n ����� ������ - " << gosp[i].g_name << "\n ������� - " << gosp[i].expenses << endl;

	cout << endl << endl << endl;
	return 0;
}

void print(EconAct* gosp, int n) {
	if (n % 2 == 0)
		for (int i = 0; i < n;) {
			/*cout << " ������������ ����� - " << gosp[i++].f_name << "\t ������������ ����� - " << gosp[i].f_name << endl;
			i--;
			cout << " ��� �������� - " << gosp[i++].activity << "\t ��� �������� - " << gosp[i].activity << endl;
			i--;*/
			if (strlen(gosp[i].g_name) < 8)
				cout << " ����� ������ - " << gosp[i].g_name << "\t\t ����� ������ - " << gosp[i + 1].g_name << endl;
			else
				cout << " ����� ������ - " << gosp[i].g_name << "\t ����� ������ - " << gosp[i + 1].g_name << endl;
			cout << " ������� - " << gosp[i].expenses << "\t\t\t ������� - " << gosp[i + 1].expenses << endl;
			i += 2;
			cout << endl;
		}
	else {
		for (int i = 0; i < n - 1;) {
			/*cout << " ������������ ����� - " << gosp[i++].f_name << "\t ������������ ����� - " << gosp[i].f_name << endl;
			i--;
			cout << " ��� �������� - " << gosp[i++].activity << "\t ��� �������� - " << gosp[i].activity << endl;
			i--;*/
			if (strlen(gosp[i].g_name) < 8)
				cout << " ����� ������ - " << gosp[i].g_name << "\t\t ����� ������ - " << gosp[i + 1].g_name << endl;
			else
				cout << " ����� ������ - " << gosp[i].g_name << "\t ����� ������ - " << gosp[i + 1].g_name << endl;
			cout << " ������� - " << gosp[i].expenses << "\t\t\t ������� - " << gosp[i + 1].expenses << endl;
			i += 2;
			cout << endl;
		}
		/*cout << " ������������ ����� - " << gosp[n - 1].f_name << endl;
		cout << " ��� �������� - " << gosp[n - 1].activity << endl;*/
		cout << " ����� ������ - " << gosp[n - 1].g_name << endl;
		cout << " ������� - " << gosp[n - 1].expenses << endl;
		cout << endl << endl;
	}
}