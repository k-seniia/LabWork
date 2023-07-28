#pragma region Includes
#include <iostream>
#include <iomanip>
#include <locale>
#include "windows.h"
using namespace std;
#pragma endregion

int main() {
#pragma region Ukranian
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Ukrainian");
#pragma endregion
	srand(time(NULL));

	int m = rand() % 8 + 2, n = rand() % 8 + 2;
	double** b = new double* [m];
	double* c = new double[n] {};
	for (int i = 0; i < m; i++)
		b[i] = new double[n];

	cout << " Початковий масив:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			b[i][j] = rand() % 100 / 10.;
			cout << setw(6) << b[i][j];
		}
		cout << endl;
	}
	cout << " Сумми стовпців:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			c[i] += b[j][i];
		cout << setw(6) << c[i];
	}

	for (int i = 0; i < m; i++)
		delete[] b[i];
	delete[] b, c;

	cout << "\n\n\n";
	return EXIT_SUCCESS;
}