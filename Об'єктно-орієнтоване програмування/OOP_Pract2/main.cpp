#include "Header.h"
#include <iostream>
using namespace std;

//26) «Матриця довільної розмірності».
//Дані класу : кількість рядків, кількість стовпців, динамічно розташований масив елементів матриці.
//Функції класу : додавання й множення матриць, множення й додавання матриці із цілим числом, порівняння двох матриць.

int main() {
	//srand(time(NULL));

	Matrix m1;
	int a = rand() % 8 + 2, b = rand() % 8 + 2, c = rand() % 8 + 2, n{};
	//m1.setrc(a, b);
	cin >> m1;

	cout << "m1" << endl;
	cout << m1;

	Matrix m2 = Matrix(b, c);
	cout << "m2" << endl;
	cout << m2;

	cout << "m1 + m2" << endl;
	cout << m1 + m2;

	cout << "m1 + " << c << endl;
	cout << m1 + c;

	cout << "m1 == m2 -> ";
	cout << boolalpha << (m1 == m2) << endl;

	cout << "m1 * m2" << endl;
	cout << m1 * m2;

	cout << "m1 * " << c << endl;
	cout << m1 + c;

	cout << "m3 = m1 + m1" << endl;
	Matrix m3 = m1 + m1;
	cout << m3;

	m1.sort();
	cout << "m1 after sort" << endl;
	cout << m1;

	cout << "Enter the number of matrices -> "; cin >> n;
	Matrix* mas = new Matrix[n];
	for (int i = 0; i < n; i++) {
		a = rand() % 8 + 2, b = rand() % 8 + 2;
		//mas[i].setrc(a, b);
		cin >> mas[i];
		cout << "mas[" << i + 1 << "]" << endl;
		cout << mas[i];
	}

	cout << Matrix::get_count() << endl;

	return 0;
}