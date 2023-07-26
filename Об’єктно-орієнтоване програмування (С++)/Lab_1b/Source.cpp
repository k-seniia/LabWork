#include "Header.h"

Figure::Figure(const int& a0, const int& b0, const int& c0) : a(a0), b(b0), c(c0) {}

//void Figure::set_t(const int& a0, const int& b0, const int& c0) { a = a0; b = b0; c = c0; }
//void Figure::set_a(const int& a0) { a = a0; }
//void Figure::set_b(const int& b0) { b = b0; }
//void Figure::set_c(const int& c0) { c = c0; }

//int Figure::get_a()const { return a; }
//int Figure::get_b()const { return b; }
//int Figure::get_c()const { return c; }

double Figure::S_triangle() {
	double p = (float)(a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));;
}

double Figure::S_circle() {
	return 3.14 * a * a;
}