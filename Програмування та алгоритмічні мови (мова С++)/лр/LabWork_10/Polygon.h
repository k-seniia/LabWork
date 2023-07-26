#pragma once
#include "Area.h"

struct Point
{
	int x, y;

	Point();
	Point(const int& x, const int& y);

	friend ostream& operator<<(ostream& out, const Point& p);
	bool operator==(const Point& p) const;
};

class Polygon : public Area
{
protected:
	int n;						// кількість точок
	std::vector<Point> points;	// масив точок
public:
	Polygon();
	Polygon(const vector<Point>& points);
	Polygon(const Polygon& p);

	double perimeter() const;
	double area() const;

	friend istream& operator>>(istream& in, Polygon& p);
	friend ostream& operator<<(ostream& out, const Polygon& p);
};

/// <summary>
/// Функція для тестування об'єктів класу Polygon
/// </summary>
void testPolygon();

// клас виключень
class NonPolygon :public exception {
public:
	/// <summary>
	/// містить текст помилки
	/// </summary>
	/// <returns> рядок з текстом помилки </returns>
	const char* what() const noexcept;
};