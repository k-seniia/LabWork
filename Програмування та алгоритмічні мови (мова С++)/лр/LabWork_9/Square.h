#pragma once
#include <iostream>
#include <cmath>
#include <exception>
#include <vector>
using namespace std;

struct Point {
	int x, y;

	// конструктор
	Point(int x, int y);

	// перевантаження оператора виведення
	friend ostream& operator<<(ostream& out, const Point& p);
};

class Square
{
	Point p1, p2;	// протилежні точок квадрату

	/// <summary>
	/// розрахунок площі квадрату
	/// </summary>
	/// <returns> площа квадрату </returns>
	int area() const;
public:
	// конструктори
	Square();
	Square(const int& x1, const int& y1, const int& x2, const int& y2);
	Square(const Square& sq);

	// перевантаження операторів введення-виведення
	friend ostream& operator<<(ostream& out, const Square& sq);
	friend istream& operator>>(istream& in, Square& sq);

	/// <summary>
	/// отримання довжини діагоналі квадрату
	/// </summary>
	/// <returns> довжина діагоналі квадрату </returns>
	double diagonal() const;
	
	/// <summary>
	/// отримання значення координати точки об’єкту, найближчої до початку координат
	/// </summary>
	/// <returns> найближча точка до початку координат </returns>
	Point closest() const;

	//перевантаження логічних операторів, квадрати порівнюються за площею
	friend bool operator==(const Square& sq1, const Square& sq2);
	friend bool operator!=(const Square& sq1, const Square& sq2);
	friend bool operator<(const Square& sq1, const Square& sq2);
	friend bool operator<=(const Square& sq1, const Square& sq2);
	friend bool operator>(const Square& sq1, const Square& sq2);
	friend bool operator>=(const Square& sq1, const Square& sq2);
};

// клас виключень
class NonSquare :public exception {
public:
	/// <summary>
	/// містить текст помилки
	/// </summary>
	/// <returns> рядок з текстом помилки </returns>
	const char* what() const noexcept;
};