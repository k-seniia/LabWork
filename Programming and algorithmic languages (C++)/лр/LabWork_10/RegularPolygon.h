#pragma once
#include "Polygon.h"

class RegularPolygon : public Polygon
{
	double side;	// довжина сторони
public:
	RegularPolygon();
	RegularPolygon(const vector<Point>& points);
	RegularPolygon(const vector<Point>& points, double side);
	RegularPolygon(const Polygon& p);

	double perimeter() const;
	double area() const;

	friend istream& operator>>(istream& in, RegularPolygon& p);
	friend ostream& operator<<(ostream& out, const RegularPolygon& p);
};

/// <summary>
/// Функція для тестування об'єктів класу RegularPolygon
/// </summary>
void testRegularPolygon();

// клас виключень
class NonRegularPolygon :public exception {
public:
	/// <summary>
	/// містить текст помилки
	/// </summary>
	/// <returns> рядок з текстом помилки </returns>
	const char* what() const noexcept;
};