#pragma once
#include <iostream>
using namespace std;

class Point {
	int x;
	int y;

public:
	Point();
	Point(const int& x0, const int& y0);
	Point(const Point &ob);
	
	void set(const int& x0, const int& y0);
	void set_x(const int& x0);
	void set_y(const int& y0);

	/*int get_x()const;
	int get_y()const;*/

	int sum(const Point& ob);
	int multi(const Point& ob);
	
	void show()const;

};