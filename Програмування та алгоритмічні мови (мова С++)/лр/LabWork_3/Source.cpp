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
	fstream fin("data_task1.bin", ios::in | ios::binary);
#else
	debug_file_task1();
	fstream fin("debug_data_task1.bin", ios::in | ios::binary);
#endif

	int i{};

	if (fin) {
		fin.read((char*)&n, sizeof(n));
		fin.read((char*)&a, sizeof(a));
		arr = new float[n];
		for (i = 0; i < n && !fin.eof(); i++)
			fin.read((char*)&arr[i], sizeof(arr[i]));
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
	fstream fout("result_task1.bin", ios::out | ios::binary);

	for (int i = 0; i < n; i++)
		fout.write((char*)&x[i], sizeof(x[i]));

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
	fstream fin("data_task2.bin", ios::in | ios::binary);
#else
	debug_file_task2();
	fstream fin("debug_data_task2.bin", ios::in | ios::binary);
#endif

	int i{};

	if (fin) {
		fin.read((char*)&m, sizeof(m));
		fin.read((char*)&n, sizeof(n));
		arr = new float* [m];
		for (int i = 0; i < m; i++)
			arr[i] = new float[n];
		for (i = 0; i < m && !fin.eof(); i++)
			for (int j = 0; j < n; j++)
				fin.read((char*)&arr[i][j], sizeof(arr[i][j]));
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
	fstream fout("result_task2.bin", ios::out | ios::binary);

	for (int i = 0; i < m; i++)
		fout.write((char*)&b[i], sizeof(b[i]));

	fout.close();
}

// write random data to the file for debug task1
void debug_file_task1() {
	fstream fout("debug_data_task1.bin", ios::out | ios::binary);

	int n = rand() % 8 + 2;
	float a = rand() % 100 / 10., arr{};
	fout.write((char*)&n, sizeof(n));
	fout.write((char*)&a, sizeof(a));
	for (int i = 0; i < n; i++) {
		arr = rand() % 200 / 10.;
		fout.write((char*)&arr, sizeof(arr));
	}

	fout.close();
}

// write random data to the file for debug task2
void debug_file_task2() {
	fstream fout("debug_data_task2.bin", ios::out | ios::binary);

	int n = rand() % 8 + 2;
	int m = rand() % 8 + 2;
	float arr{};
	fout.write((char*)&m, sizeof(m));
	fout.write((char*)&n, sizeof(n));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			arr = (rand() % 101 - 50) / 10.;
			fout.write((char*)&arr, sizeof(arr));
		}

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