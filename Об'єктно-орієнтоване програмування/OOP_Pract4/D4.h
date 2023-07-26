#pragma once
#include"B2.h"
#include "D1.h"

class D4 : private B2, public D1
{
	double x4, y4, z4;
public:
	D4(const int& a = 0, const int& b = 0, const int& c = 0, const double& x = 0.0, const double& y = 0.0, const double& z = 0.0);
	D4(const int& a, const int& b, const int& c, const double& x, const double& y, const double& z, const B2& ob);
	D4(const int& a, const int& b, const int& c, const double& x, const double& y, const double& z, const D1& ob);
	D4(const double& x, const double& y, const double& z, const B2& ob1, const D1& ob2);
	D4(const D4& ob);

	void set_D4(const int& a, const int& b, const int& c, const double& x, const double& y, const double& z);
	void set_x4(const double& x);
	void set_y4(const double& y);
	void set_z4(const double& z);

	double get_x4() const;
	double get_y4() const;
	double get_z4() const;

	friend istream& operator>>(istream& in, D4& ob);
	friend ostream& operator<<(ostream& out, const D4& ob);

	~D4();
};