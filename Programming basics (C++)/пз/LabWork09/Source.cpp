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

	const int m = 2, n = 4;
	double b[m][n] = { {4,10,1.5,20},{5,3,15,4.5} }, c[n]{};
	cout << " Початковий масив:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << setw(6) << b[i][j];
		cout << endl;
	}
	cout << " Сумми стовпців:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			c[i] += b[j][i];
		cout << setw(6) << c[i];
	}

	cout << "\n\n\n";
	return EXIT_SUCCESS;
}