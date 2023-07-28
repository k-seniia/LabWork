#pragma once
#include "B2.h"

class D2 : private B2
{
protected:
	double x2, y2, z2;
public:
	D2(const int& a = 0, const int& b = 0, const int& c = 0, const double& x = 0.0, const double& y = 0.0, const double& z = 0.0);
	D2(const double& x, const double& y, const double& z, const B2& ob);
	D2(const D2& ob);

	void set_D2(const int& a, const int& b, const int& c, const double& x, const double& y, const double& z);
	void set_x2(const double& x);
	void set_y2(const double& y);
	void set_z2(const double& z);

	double get_x2() const;
	double get_y2() const;
	double get_z2() const;

	friend istream& operator>>(istream& in, D2& ob);
	friend ostream& operator<<(ostream& out, const D2& ob);

	~D2();
};