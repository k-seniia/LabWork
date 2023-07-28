#include "Circle.h"

Circle::Circle() :radius(0)
{
}

Circle::Circle(double r) : radius(r)
{
	if (radius <= 0) {
		throw NonCircle();
	}
}

double Circle::perimeter() const
{
	return 2 * M_PI * radius;
}

double Circle::area() const
{
	return M_PI * radius * radius;
}

istream& operator>>(istream& in, Circle& c)
{
	cout << " Enter the radius of the circle -> "; in >> c.radius;
	if (c.radius <= 0) {
		throw NonCircle();
	}
	return in;
}

ostream& operator<<(ostream& out, const Circle& c)
{
	out << " Circle radius = " << c.radius << endl;
	return out;
}

// Тестування класу Circle
void testCircle()
{
	try {
		cout << "\tCircle:" << endl;
#ifdef DEBUG
		Circle circle(rand() % 100 / 10. - 1);
#else
		Circle circle;
		cin >> circle;
#endif // DEBUG
		cout << "Circle info:" << endl;
		cout << circle << endl;
		printAreaInfo(circle);

	}
	catch (const NonCircle& e) {
		cout << e.what() << endl;
	}
}

const char* NonCircle::what() const noexcept
{
	return "Wrong data for circle";
}
