#pragma once
#include "B1.h"

class D1 : public B1
{
protected:
	double x1, y1, z1;
public:
	D1(const int& a = 0, const int& b = 0, const int& c = 0, const double& x = 0.0, const double& y = 0.0, const double& z = 0.0);
	D1(const double& x, const double& y, const double& z, const B1& ob);
	D1(const D1& ob);

	void set_D1(const int& a, const int& b, const int& c, const double& x, const double& y, const double& z);
	void set_x1(const double& x);
	void set_y1(const double& y);
	void set_z1(const double& z);

	double get_x1() const;
	double get_y1() const;
	double get_z1() const;

	D1& operator=(const D1& ob);	
	bool operator!=(const D1& other) const;

	friend istream& operator>>(istream& in, D1& ob);
	friend ostream& operator<<(ostream& out, const D1& ob);

	~D1();
};