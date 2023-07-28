#include "Header.h"

int Matrix::count = 0;

Matrix::Matrix() { count++; }
Matrix::Matrix(const int& row, const int& col) :row(row), col(col) {
	mas = new int* [row];
	for (int i = 0; i < row; i++) {
		mas[i] = new int[col];
		for (int j = 0; j < col; j++)
			mas[i][j] = rand() % 9 + 1;
	}
	count++;
}
Matrix::Matrix(const Matrix& arr) :row(arr.row), col(arr.col) {
	if (arr.mas) {
		mas = new int* [row];
		for (int i = 0; i < row; i++) {
			mas[i] = new int[col];
			for (int j = 0; j < col; j++)
				mas[i][j] = arr.mas[i][j];
		}
	}
	else
		mas = 0;
	count++;
}

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

Matrix Matrix::operator+(const Matrix& arr) {
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

Matrix Matrix::operator+(const int& n) {
	Matrix res(row, col);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			res.mas[i][j] = mas[i][j] + n;
	return res;
}

Matrix Matrix::operator*(const Matrix& arr) {
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

Matrix Matrix::operator*(const int& n) {
	Matrix res(row, col);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			res.mas[i][j] = mas[i][j] * n;
	return res;
}

Matrix Matrix::operator=(const Matrix& arr) {
	if (this != &arr) {
		if (mas) {
			for (int i = 0; i < row; i++)
				delete[] mas[i];
			delete[] mas;
		}
		row = arr.row;
		col = arr.col;
		new_mas();
		for (int i = 0; i < row; i++)
			mas[i] = arr.mas[i];
	}
	return *this;
}

bool Matrix::operator==(const Matrix& arr) {
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
istream& operator>>(istream& in, Matrix& arr) {
	cout << "Enter row -> "; in >> arr.row;
	cout << "Enter col -> "; in >> arr.col;
	arr.new_mas();
	arr.fill_rand();
	return in;
}

ostream& operator<<(ostream& out, const Matrix& arr) {
	for (int i = 0; i < arr.row; i++) {
		for (int j = 0; j < arr.col; j++)
			out << setw(4) << arr.mas[i][j];
		out << endl;
	}
	out << endl;
	return out;
}

Matrix::~Matrix() {
	for (int i = 0; i < row; ++i)
		delete[] mas[i];
	delete[] mas;
	count--;
}