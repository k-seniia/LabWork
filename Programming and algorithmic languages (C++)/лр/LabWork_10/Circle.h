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
/// Функція для тестування об'єктів класу Circle
/// </summary>
void testCircle();

// клас виключень
class NonCircle :public exception {
public:
	/// <summary>
	/// містить текст помилки
	/// </summary>
	/// <returns> рядок з текстом помилки </returns>
	const char* what() const noexcept;
};