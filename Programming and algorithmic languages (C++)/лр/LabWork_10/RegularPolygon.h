#pragma once
#include "Polygon.h"

class RegularPolygon : public Polygon
{
	double side;	// ������� �������
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
/// ������� ��� ���������� ��'���� ����� RegularPolygon
/// </summary>
void testRegularPolygon();

// ���� ���������
class NonRegularPolygon :public exception {
public:
	/// <summary>
	/// ������ ����� �������
	/// </summary>
	/// <returns> ����� � ������� ������� </returns>
	const char* what() const noexcept;
};