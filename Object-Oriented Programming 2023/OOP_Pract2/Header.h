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

	Matrix operator+(const Matrix& arr);
	Matrix operator+(const int& n);

	Matrix operator*(const Matrix& arr);
	Matrix operator*(const int& n);

	Matrix operator=(const Matrix& arr);

	bool operator==(const Matrix& ar);

	void sort();

	int getr() const;
	int getc() const;
	static int get_count();

	void setrc(const int& r, const int& c);
	friend istream& operator>>(istream& in, Matrix& arr);

	friend ostream& operator<<(ostream& out, const Matrix& arr);

	~Matrix();
};