#pragma once
#include "Area.h"

class Ellipse : public Area
{
	double a; // ������ �����
	double b; // ���� �����
public:
	Ellipse();
	Ellipse(double a, double b);

	double perimeter() const;
	double area() const;

	friend istream& operator>>(istream& in, Ellipse& e);
	friend ostream& operator<<(ostream& out, const Ellipse& e);
};

/// <summary>
/// ������� ��� ���������� ��'���� ����� Ellipse
/// </summary>
void testEllipse();

// ���� ���������
class NonEllipse :public exception {
public:
	/// <summary>
	/// ������ ����� �������
	/// </summary>
	/// <returns> ����� � ������� ������� </returns>
	const char* what() const noexcept;
};