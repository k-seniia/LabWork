#pragma region Includes
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <locale>
#include <iomanip>
#include "windows.h"
using namespace std;
#pragma endregion

#define _DEBUG

// function prototypes
void task1(); void task2();
int read_from_file_task1(int&, float&, float* (&));
void write_to_file_task1(const int&, float*);
void debug_file_task1();
int read_from_file_task2(int&, int&, float** (&));
void write_to_file_task2(const int&, float*);
void debug_file_task2();
void delete_one_dim(float* (&));
void delete_two_dim(const int&, float** (&));

int main() {
#pragma region Ukranian
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Ukrainian");
#pragma endregion
	//srand(time(NULL));

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

	float a{}, * arr = NULL, b = rand() % 100 / 10., * x = NULL;
	int n{};

	if (read_from_file_task1(n, a, arr) == 0) {

		cout << "B -> " << b << endl; //cin >> B;
		cout << "a = " << a << endl;
		cout << "A = [ ";
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << "]" << endl << endl;

		x = new float[n];
		for (int i = 0; i < n; i++) {
			x[i] = (-b * sin(a)) / arr[i];
			cout << setprecision(3) << x[i] << " ";
		}

		delete_one_dim(arr);
		write_to_file_task1(n, x);
		delete_one_dim(x);
	}
}

int read_from_file_task1(int& n, float& a, float* (&arr)) {

#ifdef DEBUG
	ifstream fin("data_task1.txt");
#else
	debug_file_task1();
	ifstream fin("debug_data_task1.txt");
#endif

	int i{};

	if (fin) {
		fin >> n >> a;
		arr = new float[n];
		for (i = 0; i < n && !fin.eof(); i++)
			fin >> arr[i];
	}
	else {
		cout << "File not found." << endl;
		fin.close();
		return -1;
	}
	if (i != n) {
		cout << "Data error." << endl;
		fin.close();
		return -1;
	}
	for (i = 0; i < n; i++)
		if (arr[i] == 0) {
			cout << "ERROR - знаменник дорівнює 0" << endl;
			return -1;
		}
	
	fin.close();
	return 0;
}

void write_to_file_task1(const int& n, float* x) {
	ofstream fout("result_task1.txt");
	
	for (int i = 0; i < n; i++)
		fout << setprecision(3) << x[i] << " ";
	
	fout.close();
}

void task2() {

	float** arr = NULL, * b = NULL, min{};
	int m{}, n{};

	if (read_from_file_task2(m, n, arr) == 0) {

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				cout << setw(4) << arr[i][j] << " ";
			cout << endl;
		}
		cout << endl;

		b = new float[m];
		for (int i = 0; i < m; i++) {
			min = arr[i][0];
			for (int j = 1; j < n; j++)
				if (arr[i][j] < min)
					min = arr[i][j];
			b[i] = min;
			cout << setw(4) << b[i] << " ";
		}

		delete_two_dim(m, arr);
		write_to_file_task2(m, b);
		delete_one_dim(b);
	}
}

int read_from_file_task2(int& m, int& n, float** (&arr)) {

#ifdef DEBUG
	ifstream fin("data_task2.txt");
#else
	debug_file_task2();
	ifstream fin("debug_data_task2.txt");
#endif

	int i{};

	if (fin) {
		fin >> m >> n;
		arr = new float* [m];
		for (int i = 0; i < m; i++)
			arr[i] = new float[n];
		for (i = 0; i < m && !fin.eof(); i++)
			for (int j = 0; j < n; j++)
				fin >> arr[i][j];
	}
	else {
		cout << "File not found." << endl;
		fin.close();
		return -1;
	}
	if (i != m) {
		cout << "Data error." << endl;
		fin.close();
		return -1;
	}
	
	fin.close();
	return 0;
}

void write_to_file_task2(const int& m, float* b) {
	ofstream fout("result_task2.txt");
	
	for (int i = 0; i < m; i++)
		fout << b[i] << " ";

	fout.close();
}

// write random data to the file for debug task1
void debug_file_task1() {
	ofstream fout("debug_data_task1.txt");

	int n = rand() % 8 + 2;
	fout << n << " " << rand() % 100 / 10. << " ";
	for (int i = 0; i < n; i++)
		fout << rand() % 200 / 10. << " ";

	fout.close();
}

// write random data to the file for debug task2
void debug_file_task2() {
	ofstream fout("debug_data_task2.txt");

	int n = rand() % 8 + 2;
	int m = rand() % 8 + 2;
	fout << m << " " << n << " ";
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fout << (rand() % 101 - 50) / 10. << " ";

	fout.close();
}

void delete_one_dim(float* (&arr)) {
	delete[] arr;
}

void delete_two_dim(const int& m, float** (&arr)) {
	for (int i = 0; i < m; i++)
		delete[] arr[i];
	delete[] arr;
}