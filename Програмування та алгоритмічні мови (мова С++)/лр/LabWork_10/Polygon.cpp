#include "Polygon.h"

Polygon::Polygon() :n(0)
{
}

Polygon::Polygon(const vector<Point>& points) : points(points), n(points.size())
{
	if (n < 3) {
		throw NonPolygon();
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j && points[i] == points[j]) {
				throw NonPolygon();
			}
}

Polygon::Polygon(const Polygon& p) :points(p.points), n(points.size())
{
}

double Polygon::perimeter() const
{
	double p{};
	for (int i = 0, j{}; i < n; i++) {
		j = (i + 1) % n;
		p += sqrt(pow(points[j].x - points[i].x, 2) + pow(points[j].y - points[i].y, 2));
	}
	return p;
}

double Polygon::area() const
{
	double area{};
	for (int i = 0, j{}; i < n; i++) {
		j = (i + 1) % n;
		area += points[i].x * points[j].y - points[j].x * points[i].y;
	}
	return abs(area) / 2.0;
}

istream& operator>>(istream& in, Polygon& p)
{
	int x, y;
	cout << " Enter the number of angels of the polygon -> "; in >> p.n;
	if (p.n < 3) {
		throw NonPolygon();
	}
	cout << " Enter the coordinated of each corner: " << endl;
	for (int i = 0; i < p.n; i++) {
		cout << i << ":\tx -> "; cin >> x;
		cout << "\ty -> "; cin >> y;
		p.points.emplace_back(x, y);
	}
	for (int i = 0; i < p.n; i++)
		for (int j = 0; j < p.n; j++)
			if (i != j && p.points[i] == p.points[j]) {
				throw NonPolygon();
			}
	return in;
}

ostream& operator<<(ostream& out, const Polygon& p)
{
	out << " The coordinates of the corntrs of the polygon:" << endl;
	for (auto& a : p.points)
		out << a << " , ";
	out << endl;
	return out;
}

// Тестування класу Polygon
void testPolygon()
{
	try {
		cout << "\tPolygon:" << endl;
#ifdef DEBUG
		vector<Point> points;
		for (int i = 0; i < rand() % 10; i++)
			points.emplace_back(rand() % 10, rand() % 10);
		Polygon polygon(points);
#else
		Polygon polygon;
		cin >> polygon;
#endif // DEBUG
		cout << "Polygon info:" << endl;
		cout << polygon << endl;
		printAreaInfo(polygon);
	}
	catch (const NonPolygon& e) {
		cout << e.what() << endl;
	}
}

Point::Point() :x(0), y(0)
{
}

Point::Point(const int& x, const int& y) :x(x), y(y)
{
}

bool Point::operator==(const Point& p) const
{
	return (x == p.x && y == p.y);
}

ostream& operator<<(ostream& out, const Point& p)
{
	out << "(" << p.x << "," << p.y << ")";
	return out;
}

const char* NonPolygon::what() const noexcept
{
	return "Wrong data for polygon";
}
