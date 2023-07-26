#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstdio>
#include <fstream>
#include "windows.h"
//������������ ���� ����� ���������
using namespace std;

#pragma warning(disable : 4996)

void task1(); void task2(); void task3(); void task4(); void task5();

int main() {
#pragma region Ukranian
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Ukrainian");
#pragma endregion
	srand(time(NULL));

	for (;;) {
		int choise{};
		cout << "����i�� �������� - �i� 1 �� 5" << endl;
		cout << "0 - ���i� i� ��������" << endl << endl;
		cout << "��� ���i� -> "; cin >> choise; cout << endl;

		switch (choise) {
		case 0: return 0; break;
		case 1: task1(); break;
		case 2: task2(); break;
		case 3: task3(); break;
		case 4: task4(); break;
		case 5: task5(); break;
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
	struct exam {
		string subj{};
		int num_lw{};
		struct {
			char name[9]{};
			int am_s{};
		};
	};

	const char* name[] = { "���", "���̲", "�в̲", "���", "�Ҳ�" };
	const char* subjects[] = { "���", "��", "����", "��", "Բ�" };

	const int n = 20;
	exam mas[n];

	string gr_nm{};
	for (int i = 0; i < n; i++) {
		mas[i].am_s = rand() % 20 + 10;
		gr_nm = name[rand() % 5] + to_string((rand() % 4 + 19) * -1) + to_string((rand() % 5 + 1) * -1);
		strcpy(mas[i].name, const_cast<char*>(gr_nm.c_str()));
		mas[i].num_lw = rand() % 8 + 2;
		mas[i].subj = subjects[rand() % 5];
		cout << "��������� - " << mas[i].subj << ", ������� �� - " << mas[i].num_lw
			<< "\t����� - " << mas[i].name << ", " << mas[i].am_s << " ��������" << endl;
	}

	cout << endl << endl << "������: ";

	bool flag = false;
	for (int i = 0; i < n; i++)
		if (mas[i].subj == "���" && strncmp(mas[i].name, "���", 3) == 0) {
			cout << "\n\t��������� - " << mas[i].subj << "\t����� - " << mas[i].name;
			flag = true;
			break;
		}
	if (!flag)
		cout << "������" << endl;

}

void task2() {
	struct student2 {
		char faculty[5]{};
		char group[11]{};
		char name[9]{};
		double gpa{};
	};

	const int n = 20;
	student2 st[n];

	const char* l_name[] = { "��������","�������","�����","�������","ѳ����","ʳ�","��������","�������","������","����" };
	const char* fac[] = { "��","ʲ�","���","���","��","����","���ǲ" };
	const char* gr[] = { "����","���","��ز","ʲ�ʲ","�вʲ","���Ѳ","�ʲ��","���","�����","�в̲" };

	ofstream fout("bd.txt");
	for (int i = 0; i < n; i++)
		fout << fac[rand() % 7] << ":" << gr[rand() % 10] << "-" << rand() % 4 + 19 << "-" << rand() % 5 + 1 << " " << l_name[rand() % 10] << ":" << fixed << setprecision(1) << (rand() % 30 + 20) / 10. << endl;
	fout.close();

	char buf[30];
	int i{};
	ifstream fin("bd.txt");
	while (!fin.eof()) {
		fin.getline(buf, 30, '\n');
		if (!strlen(buf)) continue;
		strcpy(st[i].faculty, strtok(buf, ":"));
		strcpy(st[i].group, strtok(NULL, " "));
		strcpy(st[i].name, strtok(NULL, ":"));
		st[i].gpa = atoi(strtok(NULL, ".")) + (atoi(strtok(NULL, "\0")) / 10.);
		if (st[i].gpa < 4.49 && strncmp(st[i].faculty, "��", 2) == 0)
			cout << st[i].name << " " << st[i].group << endl;
		i++;
	}
	fin.close();

}

void task3() {
	struct student3 {
		const char* f_name{};
		const char* l_name{};
		int phys{};
		int chem{};
		int math{};
	};

	const char* f_name[] = { "����", "������", "����", "����", "���", "�����" };
	const char* l_name[] = { "��������", "�������", "�����", "�������", "ѳ����", "ʳ�" };

	int n = rand() % 8 + 2; cout << "ʳ������ �������� - " << n << endl;
	student3* stud = new student3[n];
	cout << "��������:" << endl;
	for (int i = 0; i < n; i++) {
		stud[i].f_name = f_name[rand() % 6];
		stud[i].l_name = l_name[rand() % 6];
		if (i != 0 && stud[i].f_name == stud[i - 1].f_name && stud[i].l_name == stud[i - 1].l_name) {
			i--;
			continue;
		}
		if (i % 5 == 0 && i != 0)
			cout << endl;
		cout << stud[i].f_name << " " << stud[i].l_name << "     ";
		stud[i].phys = rand() % 4 + 2;
		stud[i].chem = rand() % 4 + 2;
		stud[i].math = rand() % 4 + 2;
	}

	string fn; cout << "\n\n������ ��'� -> "; cin >> fn;
	string ln; cout << "������ ������� -> "; cin >> ln;
	int count{};
	for (int i = 0; i < n; i++) {
		if (stud[i].f_name == fn && stud[i].l_name == ln) {
			cout << "\nԳ���� - " << stud[i].phys
				<< "\tճ�� - " << stud[i].chem
				<< "\t���������� - " << stud[i].math;
			break;
		}
		else
			count++;
	}
	if (count == n)
		cout << "Error";

}

//task4

struct Flat {
	const char* address{};
	int rooms{};
	int area{};
	int cost{};
};

void print4(const Flat& f); void search(Flat* f, int n, int sum);

void task4() {
	int num{};
	cout << "������ ������� ������� ������� -> "; //cin >> num;
	num = rand() % 20 + 10; cout << num << endl;

	Flat* f = new Flat[num];

	const char* streets[] = { "���������","���������","����������","������","������","������������","�����������","˳����","����������","�����������" };

	cout << endl << endl;

	for (int i = 0; i < num; i++) {
		f[i].address = streets[rand() % 10];

		f[i].rooms = rand() % 4 + 1;
		switch (f[i].rooms) {
		case 1: f[i].area = rand() % 10 + 30; break;
		case 2: f[i].area = rand() % 18 + 38; break;
		case 3: f[i].area = rand() % 24 + 56; break;
		case 4: f[i].area = rand() % 26 + 59; break;
		}
		f[i].cost = rand() % 830 + 246;
		print4(f[i]);
	}

	cout << endl << endl;

	int sum{};
	cout << "������� ��������� ������� 2-������� �������� -> "; //cin >> sum;
	sum = rand() % (56 * 1076 - 38 * 246 + 1) + 38 * 246; cout << sum << endl;

	cout << endl;

	search(f, num, sum);

	delete[] f;
}

void print4(const Flat& f) {
	cout << "���. " << f.address << " - ";
	cout << f.rooms << "-�������, ";
	cout << "����� = " << f.area << " �.��., ";
	cout << f.cost << "$/�.��." << endl;
}

void search(Flat* f, int n, int sum) {
	bool flag = false;
	int price{};
	for (int i = 0; i < n; i++) {
		price = f[i].cost * f[i].area;
		if (f[i].rooms == 2 && price <= sum) {
			if (!flag)
				cout << "�� ������� ������� �������� ��� ��������: " << endl;
			cout << "\t"; print4(f[i]);
			cout << "\t�������: " << price << "$" << endl << endl;
			flag = true;
		}
	}
	if (!flag)
		cout << "�� ������� ������� - ������� �� ��������" << endl;
}

//task5

struct Student {
	char name[10]{};
	int group{};
	int ses[5]{};
};

void entry(Student* st, int n); void sort(Student* st, int n); void excellent(Student* st, int n);

void task5() {
	int n{};
	cout << "������ ������� �������� -> "; //cin >> n;
	n = rand() % 20 + 10; cout << n << endl;
	cout << endl;

	Student* st = new Student[n];

	entry(st, n);

	cout << endl << endl;

	sort(st, n);

	cout << endl << endl;

	excellent(st, n);

	delete[] st;
}

void entry(Student* st, int n) {
	const char* l_name[] = { "��������","�������","�����","�������","ѳ����","ʳ�","��������","�������","������","����" };

	for (int i = 0; i < n; i++) {
		cout << "������ ������� " << i + 1 << "-�� �������� -> "; //cin >> st[i].name;
		strcpy(st[i].name, l_name[rand() % 10]); cout << st[i].name << endl;
		cout << "������ ����� ����� " << i + 1 << "-�� �������� -> "; //cin >> st[i].group;
		st[i].group = rand() % 100 + 300; cout << st[i].group << endl;
		cout << "������ �'��� ������ " << i + 1 << "-�� �������� -> ";
		for (int j = 0; j < 5; j++) {
			//cin >> st[i].ses[j];
			st[i].ses[j] = rand() % 5 + 1; cout << st[i].ses[j] << " ";
		}
		cout << endl << endl;
	}
}

void sort(Student* st, int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (strcmp(st[j].name, st[j + 1].name) > 0) {
				swap(st[j].name, st[j + 1].name);
				swap(st[j].group, st[j + 1].group);
				for (int k = 0; k < 5; k++)
					swap(st[j].ses[k], st[j + 1].ses[k]);
			}

	for (int i = 0; i < n; i++) {
		cout << st[i].name << " - " << st[i].group << " - ";
		for (int j = 0; j < 5; j++)
			cout << st[i].ses[j] << " ";
		cout << endl;
	}
}

void excellent(Student* st, int n) {
	double gpa{}; bool flag = false;
	for (int i = 0; i < n; i++) {
		gpa = 0;
		for (int j = 0; j < 5; j++)
			gpa += st[i].ses[j];
		gpa /= 5.;
		if (gpa > 4.0) {
			if (!flag)
				cout << "�������� � ������� ����� ���� 4.0: " << endl;;
			cout << "\t" << st[i].name << " - " << st[i].group << " - " << gpa << endl;
			flag = true;
		}
	}
	if (!flag)
		cout << "�������� � ������� ����� ���� 4.0 - ������" << endl;
}