#include "Header.h"
#include <iostream>
using namespace std;

int main() {
	srand(time(NULL));

	Matrix m1;
	int a = rand() % 8 + 2, b = rand() % 8 + 2, c = rand() % 8 + 2, n{};
	m1.setrc(a, b);

	cout << "m1" << endl;
	m1.print();

	Matrix m2(b, c);
	cout << "m2" << endl;
	m2.print();

	cout << "m1 + m2" << endl;
	m1.add(m2).print();

	cout << "m1 + " << c << endl;
	m1.add_int(c).print();

	cout << "m1 = m2 -> ";
	cout << boolalpha << m1.cmp(m2) << endl;

	cout << "m1 * m2" << endl;
	m1.multi(m2).print();

	cout << "m1 * " << c << endl;
	m1.multi_int(c).print();

	cout << "m3 = m1 + m2" << endl;
	Matrix m3 = m1.add(m2);
	m3.print();

	m1.sort();
	cout << "m1 after sort" << endl;
	m1.print();

	cout << "Enter the number of matrices -> "; cin >> n;
	Matrix* mas = new Matrix[n];
	for (int i = 0; i < n; i++) {
		a = rand() % 8 + 2, b = rand() % 8 + 2;
		mas[i].setrc(a, b);
		cout << "mas[" << i + 1 << "]" << endl;
		mas[i].print();
	}

	cout << Matrix::get_count() << endl;

	return 0;
}