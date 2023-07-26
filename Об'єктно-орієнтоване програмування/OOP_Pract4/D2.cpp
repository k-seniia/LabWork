#include "D2.h"

D2::D2(const int& a, const int& b, const int& c, const double& x, const double& y, const double& z) 
	:x2(x), y2(y), z2(z), B2(a, b, c)
{
	cout << "D2: initialization constructor (default)" << endl;
}

D2::D2(const double& x, const double& y, const double& z, const B2& ob) 
	:x2(x), y2(y), z2(z), B2(ob)
{
	cout << "D2: initialization/copy constructor" << endl;
}

D2::D2(const D2& ob) 
	:x2(ob.x2), y2(ob.y2), z2(ob.z2), B2(ob)
{
	cout << "D2: copy constructor" << endl;
}

void D2::set_D2(const int& a, const int& b, const int& c, const double& x, const double& y, const double& z)
{
	set_B2(a, b, c);
	x2 = x;
	y2 = y;
	z2 = z;
}

void D2::set_x2(const double& x)
{
	x2 = x;
}

void D2::set_y2(const double& y)
{
	y2 = y;
}

void D2::set_z2(const double& z)
{
	z2 = z;
}

double D2::get_x2() const
{
	return x2;
}

double D2::get_y2() const
{
	return y2;
}

double D2::get_z2() const
{
	return z2;
}

D2::~D2()
{
	cout << "D2: destructor" << endl;
}

istream& operator>>(istream& in, D2& ob)
{
	in >> (B2&)ob;
	cout << " x2 -> "; in >> ob.x2;
	cout << " y2 -> "; in >> ob.y2;
	cout << " z2 -> "; in >> ob.z2;
	return in;
}

ostream& operator<<(ostream& out, const D2& ob)
{
	out << (B2&)ob;
	out << " x2 = " << ob.x2 << ", y2 = " << ob.y2 << ", z2 = " << ob.z2 << endl;
	return out;
}
