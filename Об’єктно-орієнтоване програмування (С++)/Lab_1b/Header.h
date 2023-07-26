#pragma once
#include <iostream>
#include <math.h>
using namespace std;

class Figure {
	int a, b, c;

public:
	Figure(const int& a0, const int& b0 = 0, const int& c0 = 0);

	/*void set_t(const int& a0, const int& b0, const int& c0);
	void set_a(const int& a0);
	void set_b(const int& b0);
	void set_c(const int& c0);*/
	
	/*int get_a()const;
	int get_b()const;
	int get_c()const;*/

	double S_triangle();
	double S_circle();
};