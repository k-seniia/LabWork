#pragma once
#include "Area.h"

class Ellipse : public Area
{
	double a; // велика піввісь
	double b; // мала піввісь
public:
	Ellipse();
	Ellipse(double a, double b);

	double perimeter() const;
	double area() const;

	friend istream& operator>>(istream& in, Ellipse& e);
	friend ostream& operator<<(ostream& out, const Ellipse& e);
};

/// <summary>
/// Функція для тестування об'єктів класу Ellipse
/// </summary>
void testEllipse();

// клас виключень
class NonEllipse :public exception {
public:
	/// <summary>
	/// містить текст помилки
	/// </summary>
	/// <returns> рядок з текстом помилки </returns>
	const char* what() const noexcept;
};