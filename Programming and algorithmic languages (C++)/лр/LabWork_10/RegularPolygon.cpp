#include "RegularPolygon.h"

RegularPolygon::RegularPolygon() :side(0)
{
}

RegularPolygon::RegularPolygon(const vector<Point>& points) : Polygon(points)
{
	side = sqrt(pow(points[0].x - points[1].x, 2) + pow(points[0].y - points[1].y, 2));
	for (int i = 0, j{}; i < n; i++) {
		j = (i + 1) % points.size();
		if (sqrt(pow(points[j].x - points[i].x, 2) + pow(points[j].y - points[i].y, 2)) != side) {
			throw NonRegularPolygon();
		}
	}
}

RegularPolygon::RegularPolygon(const vector<Point>& points, double side) : Polygon(points), side(side)
{
	for (int i = 0, j{}; i < n; i++) {
		j = (i + 1) % points.size();
		if (sqrt(pow(points[j].x - points[i].x, 2) + pow(points[j].y - points[i].y, 2)) != side) {
			throw NonRegularPolygon();
		}
	}
}

RegularPolygon::RegularPolygon(const Polygon& p) :Polygon(p)
{
	for (int i = 0, j{}; i < n; i++) {
		j = (i + 1) % points.size();
		if (sqrt(pow(points[j].x - points[i].x, 2) + pow(points[j].y - points[i].y, 2)) != side) {
			throw NonRegularPolygon();
		}
	}
}

double RegularPolygon::perimeter() const
{
	return side * n;
}

double RegularPolygon::area() const
{
	return (n * pow(side, 2)) / (4 * tan(M_PI / n));
}

istream& operator>>(istream& in, RegularPolygon& p)
{
	in >> (Polygon&)p;
	p.side = sqrt(pow(p.points[0].x - p.points[1].x, 2) + pow(p.points[0].y - p.points[1].y, 2));
	for (int i = 0, j{}; i < p.n; i++) {
		j = (i + 1) % p.points.size();
		if (sqrt(pow(p.points[j].x - p.points[i].x, 2) + pow(p.points[j].y - p.points[i].y, 2)) != p.side) {
			throw NonRegularPolygon();
		}
	}
	cout << " The length of the side of a regular polygon -> " << p.side << endl;;

	return in;
}

ostream& operator<<(ostream& out, const RegularPolygon& p)
{
	out << (Polygon&)p;
	out << " The length of the side of a regular polygon" << p.side << endl;
	return out;
}

// Тестування класу RegularPolygon
void testRegularPolygon()
{
	try {
		cout << "\tRegular Polygon:" << endl;
#ifdef DEBUG
		vector<Point> points;
		for (int i = 0; i < rand() % 10; i++)
			points.emplace_back(rand() % 10, rand() % 10);
		RegularPolygon regularPolygon(points);
#else
		RegularPolygon regularPolygon;
		cin >> regularPolygon;
#endif // DEBUG
		cout << "Regular Polygon info:" << endl;
		cout << regularPolygon << endl;
		printAreaInfo(regularPolygon);

}
	catch (const NonRegularPolygon& e) {
		cout << e.what() << endl;
	}
}

const char* NonRegularPolygon::what() const noexcept
{
	return "Wrong data for regular polygon";
}
