#pragma once
#include "D1.h"

class D3 : private D1
{
	double x3, y3, z3;
public:
	D3(const int& a = 0, const int& b = 0, const int& c = 0, const double& x = 0.0, const double& y = 0.0, const double& z = 0.0);
	D3(const double& x, const double& y, const double& z, const D1& ob);
	D3(const D3& ob);

	void set_D3(const int& a, const int& b, const int& c, const double& x, const double& y, const double& z);
	void set_x3(const double& x);
	void set_y3(const double& y);
	void set_z3(const double& z);

	double get_x3() const;
	double get_y3() const;
	double get_z3() const;

	friend istream& operator>>(istream& in, D3& ob);
	friend ostream& operator<<(ostream& out, const D3& ob);

	~D3();
};