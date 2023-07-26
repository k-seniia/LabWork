#pragma once
#include "Area.h"

class Circle : public Area
{
	double radius;
public:
	Circle();
	Circle(double r);

	double perimeter() const;
	double area() const;

	friend istream& operator>>(istream& in, Circle& c);
	friend ostream& operator<<(ostream& out, const Circle& c);
};

/// <summary>
/// ������� ��� ���������� ��'���� ����� Circle
/// </summary>
void testCircle();

// ���� ���������
class NonCircle :public exception {
public:
	/// <summary>
	/// ������ ����� �������
	/// </summary>
	/// <returns> ����� � ������� ������� </returns>
	const char* what() const noexcept;
};