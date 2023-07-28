#include "Square.h"

Point::Point(int x, int y) :x(x), y(y) {}

ostream& operator<<(ostream& out, const Point& p)
{
	out << "x: " << p.x << ", y: " << p.y;
	return out;
}

Square::Square() :p1(1, 1), p2(-1, -1) {}

Square::Square(const int& x1, const int& y1, const int& x2, const int& y2) :p1(x1, y1), p2(x2, y2)
{
	if (abs(p2.x - p1.x) != abs(p2.y - p1.y) || p1.x == p2.x || p1.y == p2.y)
		throw NonSquare();
}

Square::Square(const Square& sq) :p1(sq.p1.x, sq.p1.y), p2(sq.p2.x, sq.p2.y) {}

ostream& operator<<(ostream& out, const Square& sq)
{
	out << "\tp1: (" << sq.p1 << ")" << endl;
	out << "\tp2: (" << sq.p2 << ")" << endl;
	return out;
}

istream& operator>>(istream& in, Square& sq)
{
	cout << "p1: " << endl;
	cout << "\tx -> "; in >> sq.p1.x;
	cout << "\ty -> "; in >> sq.p1.y;
	cout << "p2: " << endl;
	cout << "\tx -> "; in >> sq.p2.x;
	cout << "\ty -> "; in >> sq.p2.y;
	if (abs(sq.p2.x - sq.p1.x) != abs(sq.p2.y - sq.p1.y) || sq.p1.x == sq.p2.x || sq.p1.y == sq.p2.y)
		throw NonSquare();
	return in;
}

int Square::area() const
{
	return abs(p2.x - p1.x) * abs(p2.y - p1.y);
}

double Square::diagonal() const
{
	return sqrt(2 * this->area());
}

Point Square::closest() const
{
	int x1y1 = sqrt(p1.x * p1.x + p1.y * p1.y);
	int x1y2 = sqrt(p1.x * p1.x + p2.y * p2.y);
	int x2y1 = sqrt(p2.x * p2.x + p1.y * p1.y);
	int x2y2 = sqrt(p2.x * p2.x + p2.y * p2.y);
	if (x1y1 <= x1y2 && x1y1 <= x2y1 && x1y1 <= x2y2)
		return p1;
	if (x1y2 <= x1y1 && x1y2 <= x2y1 && x1y2 <= x2y2)
		return Point(p1.x, p2.y);
	if (x2y1 <= x1y1 && x2y1 <= x1y2 && x2y1 <= x2y2)
		return Point(p2.x, p1.y);
	if (x2y2 <= x1y2 && x2y2 <= x2y1 && x2y2 <= x1y1)
		return p2;
}

bool operator==(const Square& sq1, const Square& sq2)
{
	return sq1.area() == sq2.area();
}

bool operator!=(const Square& sq1, const Square& sq2)
{
	return sq1.area() != sq2.area();
}

bool operator<(const Square& sq1, const Square& sq2)
{
	return sq1.area() < sq2.area();
}

bool operator<=(const Square& sq1, const Square& sq2)
{
	return sq1.area() <= sq2.area();
}

bool operator>(const Square& sq1, const Square& sq2)
{
	return sq1.area() > sq2.area();
}

bool operator>=(const Square& sq1, const Square& sq2)
{
	return sq1.area() >= sq2.area();
}

const char* NonSquare::what() const noexcept
{
	return "The points do not form a square.";
}
