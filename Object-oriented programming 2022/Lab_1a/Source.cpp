#include "Header.h"

Point::Point(): x(0), y(0) {}
Point::Point(const int& x0, const int& y0): x(x0), y(y0) {}
Point::Point(const Point& ob): x(ob.x), y(ob.y) {}

void Point::set(const int& x0, const int& y0) { x = x0; y = y0; }
void Point::set_x(const int& x0) { x = x0; }
void Point::set_y(const int& y0) { y = y0; }

//int Point::get_x()const { return x; }
//int Point::get_y()const { return y; }

int Point::sum(const Point& ob) { return ob.x + ob.y; }

int Point::multi(const Point& ob) { return ob.x * ob.y; }

void Point::show()const { cout << "x = " << x << "   " << "y = " << y << endl; }