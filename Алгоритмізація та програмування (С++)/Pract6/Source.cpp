#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstdio>
#include "windows.h"
//������ � ������� �� ���������
using namespace std;

#pragma warning(disable : 4996)

void task1(); void task2(); void task3(); void task4(); void task5();
void task6(); void task7(); void task8(); void task9(); void task10();

int main() {
#pragma region Ukranian
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Ukrainian");
#pragma endregion
	srand(time(NULL));

	for (;;) {
		int choise{};
		cout << "����i�� �������� - �i� 1 �� 10" << endl;
		cout << "0 - ���i� i� ��������" << endl << endl;
		cout << "��� ���i� -> "; cin >> choise; cout << endl;

		switch (choise) {
		case 0: return 0; break;
		case 1: task1(); break;
		case 2: task2(); break;
		case 3: task3(); break;
		case 4: task4(); break;
		case 5: task5(); break;
		case 6: task6(); break;
		case 7: task7(); break;
		case 8: task8(); break;
		case 9: task9(); break;
		case 10: task10(); break;
		default: cout << "���i���� ���i�, ������i�� ENTER �� ����i�� �����" << endl; break;
		}
		cout << endl << endl;
		system("pause");
		system("cls");
	}

	cout << "\n\n\n\n\n";
	return 0;
}

void task1() {
	string s;
	cout << "������ ����� -> "; cin.get(); getline(cin, s);
	int let{}, num{}, spa{}, sim{};
	for (int i = 0; i < size(s); i++)
		if ((int)s[i] > 64 && (int)s[i] < 91 || (int)s[i]>96 && (int)s[i] < 123) {
			let++;
			s[i] = toupper(s[i]);
		}
		else if ((int)s[i] > 47 && (int)s[i] < 58) num++;
		else if (s[i] == ' ') spa++;
		else sim++;

	cout << "\nʳ������ ���� = " << let << endl;
	cout << "ʳ������ ���� = " << num << endl;
	cout << "ʳ������ �������� = " << spa << endl;
	cout << "ʳ������ ������� ���������� = " << sim << endl << endl;;
	cout << s << endl;;
}

void task2() {
	char s[100];
	cout << "������ ����� -> "; cin.get(); cin.getline(s, 100, '\n');
	int word{}, i{}, count{};
	char* tk; const char* spt = " ,.!";
	tk = strtok(s, spt);
	while (tk != NULL) { // while (tk)
		tk = strtok(NULL, spt);
		count++;
	}

	cout << "ʳ������ ��� � ����� = " << count;
}

void task3() {
	string s;
	cout << "������ ����� -> "; cin.get(); getline(cin, s);
	for (int i = 0; i < size(s) / 2; i++) {
		char temp = s[i];
		s[i] = s[size(s) - i - 1];
		s[size(s) - i - 1] = temp;
	}
	cout << s;
}

void task4() {
	char s[100];
	cout << "������ ����� -> "; cin.get(); cin.getline(s, 100, '\n');
	char* tk; const char* spt = " ,.!";
	int � = 1;
	tk = strtok(s, spt);
	while (tk != NULL) { // while (tk)
		cout << � << " ����� - " << tk << " - ������ " << strlen(tk) << " �������" << endl;
		tk = strtok(NULL, spt);
		�++;
	}
}

void task5() {
	char  temp[30], buf[5][30];/*{ "Dixon", "Moore", "Brock", "Mitchell", "Ford" };*/
	cout << "������ 5 ������ -> ";
	for (int i = 0; i < 5; i++)
		cin >> buf[i];

	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++)
			if (strcmp(buf[i], buf[j]) > 0) {
				strcpy(temp, buf[i]);
				strcpy(buf[i], buf[j]);
				strcpy(buf[j], temp);
			}
		cout << buf[i] << " ";
	}
}

void task6() {
	char s[256], sym[10];
	cout << "������ ����� -> "; cin.get(); cin.getline(s, 256, '\n');
	cout << "������ ����� ������� -> "; cin.getline(sym, 10, '\n');

	int j{}, count{}, enter{};
	for (int i = 0; i < strlen(s); i++) {
		j = 0, count = 0;
		if (s[i] == sym[j])
			for (; j < strlen(sym); j++)
				if (s[i + j] == sym[j]) count++;
				else break;
		if (count == strlen(sym)) enter++;
	}
	cout << "ʳ������ �������� � ����� = " << enter;
}

void task7() {
	char s[256], sym[10];
	cout << "������ ����� -> "; cin.get(); cin.getline(s, 256, '\n');
	cout << "������ ������� -> "; cin.getline(sym, 10, '\n');

	if (strstr(s, sym) != NULL) cout << "������� ��������� ������� = " << strlen(s) - strlen(strstr(s, sym));
	else cout << "������� ��������� ������� �������";
}

void task8() {
	char s[256], sym;
	cout << "������ ����� -> "; cin.get(); cin.getline(s, 256, '\n');
	cout << "������ ������ -> "; cin >> sym;

	int count{}, stop = strlen(strrchr(s, sym)), mem{};
	if (strchr(s, sym) != NULL) {
		cout << "������� ��������� ������� : ";
		while (strlen(s) > stop) {
			cout << strlen(s) - strlen(strchr(s, sym)) + mem << " ";
			mem = strlen(s) - strlen(strchr(s, sym)) + 1 + mem;
			strcpy(s, strchr(s, sym) + 1);
			count++;
		}
		cout << "\nʳ������ �������� � ����� = " << count;
	}
	else cout << "������� ��������� ������� �������";
}

void task9() {
	char s[256], sym[10], res[256]{};
	cout << "������ ����� -> "; cin.get(); cin.getline(s, 256, '\n');
	cout << "������ ����� ������� -> "; cin.getline(sym, 10, '\n');

	if (strlen(s) != strcspn(s, sym)) {
		while (strlen(s) > strcspn(s, sym)) {
			strncat(res, s, strcspn(s, sym));
			strcpy(s, s + strcspn(s, sym) + 1);
		}
		strcat(res, s);
		cout << res;
	}
	else cout << "";
}

void task10() {
	char buf[5][30], beg, end[5];
	cout << "������ 5 ������ -> ";
	for (int i = 0; i < 5; i++)
		cin >> buf[i];
	cout << "����� ����� -> "; cin >> beg;
	cout << "��������� -> "; cin >> end;
	int end_l = strlen(end), buf_l{}, count{}, non{};

	for (int i = 0; i < 5; i++) {
		if (buf[i][0] == beg) {
			buf_l = strlen(buf[i]);
			for (int j = end_l - 1; j >= 0; j--)
				if (buf[i][buf_l - end_l + j] == end[j])
					count++;
			if (count == end_l)	cout << "������ ������� - " << buf[i] << endl;
			else non++;
			count = 0;
		}
		else non++;
	}
	if (non == 5) cout << "��������� ������� �� ��������";
}