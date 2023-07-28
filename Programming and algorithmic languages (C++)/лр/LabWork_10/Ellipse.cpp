#include "Ellipse.h"

Ellipse::Ellipse() :a(0), b(0)
{
}

Ellipse::Ellipse(double a, double b) : a(a > b ? a : b), b(a < b ? a : b)
{
	if (a == b || a <= 0 || b <= 0) {
		throw NonEllipse();
	}
}

double Ellipse::perimeter() const
{
	return 4 * ((M_PI * a * b + (a - b)) / (a + b));
}

double Ellipse::area() const
{
	return M_PI * a * b;
}

istream& operator>>(istream& in, Ellipse& e)
{
	cout << " Enter the length of the semi-axes of the ellipse:" << endl;
	cout << " major axis - a -> "; in >> e.a;
	cout << " minor axis - b -> "; in >> e.b;
	if (e.a == e.b || e.a <= 0 || e.b <= 0) {
		throw NonEllipse();
	}
	return in;
}

ostream& operator<<(ostream& out, const Ellipse& e)
{
	out << " major axis - a = " << e.a << endl;
	out << " minor axis - b = " << e.b << endl;
	return out;
}

// Тестування класу Ellipse
void testEllipse()
{
	try {
		cout << "\tEllipse:" << endl;
#ifdef DEBUG
		Ellipse el(rand() % 100 / 10. - 1, rand() % 100 / 10. - 1);
#else
		Ellipse el;
		cin >> el;
#endif // DEBUG
		cout << "Ellipse info:" << endl;
		cout << el << endl;
		printAreaInfo(el);
	}
	catch (const NonEllipse& e) {
		cout << e.what() << endl;
	}
}

const char* NonEllipse::what() const noexcept
{
	return "Wrong data for ellipse";
}