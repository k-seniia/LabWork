////////////////////////////////////Header.h///////////////////////////////////
#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Matrix {
	int row{};
	int col{};
	int** mas{};
	static int count;

	void new_mas();
	void fill_rand();
public:
	Matrix();
	Matrix(const int& row, const int& col);
	Matrix(const Matrix& arr);

	Matrix add(const Matrix& arr);
	Matrix add_int(const int& n);

	Matrix multi(const Matrix& arr);
	Matrix multi_int(const int& n);

	bool cmp(const Matrix& arr);
	
	void sort();
	
	int getr() const;
	int getc() const;
	static int get_count();

	void setrc(const int& r, const int& c);

	void print() const;

	~Matrix();
};

////////////////////////////////////////Source.cpp//////////////////////////////////////////
#include "Header.h"

int Matrix::count = 0;

Matrix::Matrix() { count++; }
Matrix::Matrix(const int& row, const int& col) :row(row), col(col) { new_mas(); fill_rand(); count++; }
Matrix::Matrix(const Matrix& arr) :row(arr.row), col(arr.col) { new_mas(); fill_rand(); count++; }

void Matrix::new_mas() {
	mas = new int* [row];
	for (int i = 0; i < row; i++)
		mas[i] = new int[col];
}
void Matrix::fill_rand() {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			mas[i][j] = rand() % 9 + 1;
}

Matrix Matrix::add(const Matrix& arr) {
	Matrix res;
	if (row != arr.row || col != arr.col) {
		cout << "Adding matrices of different sizes is not possible" << endl;
		res.setrc(1, 1);
		res.mas[0][0] = 0;
		return res;
	}
	res.setrc(row, col);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			res.mas[i][j] = mas[i][j] + arr.mas[i][j];
	return res;
}

Matrix Matrix::add_int(const int& n) {
	Matrix res(row, col);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			res.mas[i][j] = mas[i][j] + n;
	return res;
}

Matrix Matrix::multi(const Matrix& arr) {
	Matrix res;
	if (row != arr.col && col != arr.row) {
		cout << "Such matrices cannot be multiplied" << endl;
		res.setrc(1, 1);
		res.mas[0][0] = 0;
	}
	else if (row == arr.col) {
		res.setrc(arr.row, col);
		for (int i = 0; i < arr.row; ++i)
			for (int j = 0; j < col; ++j) {
				res.mas[i][j] = 0;
				for (int k = 0; k < arr.col; ++k)
					res.mas[i][j] += mas[k][j] * arr.mas[i][k];
			}
	}
	else if (col == arr.row) {
		res.setrc(row, arr.col);
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < arr.col; ++j) {
				res.mas[i][j] = 0;
				for (int k = 0; k < col; ++k)
					res.mas[i][j] += mas[i][k] * arr.mas[k][j];
			}
	}
	return res;
}

Matrix Matrix::multi_int(const int& n) {
	Matrix res(row, col);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			res.mas[i][j] = mas[i][j] * n;
	return res;
}

bool Matrix::cmp(const Matrix& arr) {
	if (row != arr.row || col != arr.col)
		return false;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			if (mas[i][j] != arr.mas[i][j])
				return false;
	return true;
}

void Matrix::sort() {
	for (int c = 0; c <= row * col; c++) {
		int x{}, y{};
		for (int i = 0; i < row; i++)
			for (int j = (i ? 0 : 1); j < col; j++) {
				if (mas[x][y] > mas[i][j])
					swap(mas[x][y], mas[i][j]);
				x = i; y = j;
			}
	}
}

int Matrix::getr() const { return row; }
int Matrix::getc() const { return col; }
int Matrix::get_count() { return count; }

void Matrix::setrc(const int& r, const int& c) {
	row = r; col = c;
	new_mas();
	fill_rand();
}

void Matrix::print() const {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << setw(4) << mas[i][j];
		cout << endl;
	}
	cout << endl;
}

Matrix::~Matrix() {
	for (int i = 0; i < row; ++i)
		delete[] mas[i];
	delete[] mas;
	count--;
}

//////////////////////////////////////main.cpp////////////////////////////////////////
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