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