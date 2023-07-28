#include "D1.h"

D1::D1(const int& a, const int& b, const int& c, const double& x, const double& y, const double& z)
	:x1(x), y1(y), z1(z), B1(a, b, c)
{
	cout << "D1: initialization constructor (default)" << endl;
}

D1::D1(const double& x, const double& y, const double& z, const B1& ob)
	:x1(x), y1(y), z1(z), B1(ob)
{
	cout << "D1: initialization/copy constructor" << endl;
}

D1::D1(const D1& ob)
	:x1(ob.x1), y1(ob.y1), z1(ob.z1), B1(ob)
{
	cout << "D1: copy constructor" << endl;
}

void D1::set_D1(const int& a, const int& b, const int& c, const double& x, const double& y, const double& z)
{
	set_B1(a, b, c);
	x1 = x;
	y1 = y;
	z1 = z;
}

void D1::set_x1(const double& x)
{
	x1 = x;
}

void D1::set_y1(const double& y)
{
	y1 = y;
}

void D1::set_z1(const double& z)
{
	z1 = z;
}

double D1::get_x1() const
{
	return x1;
}

double D1::get_y1() const
{
	return y1;
}

double D1::get_z1() const
{
	return z1;
}

D1& D1::operator=(const D1& ob)
{
	(B1)*this = (B1)ob;
	x1 = ob.x1;
	y1 = ob.y1;
	z1 = ob.z1;
	return *this;
}

bool D1::operator!=(const D1& other) const
{
	return (B1)*this != (B1)other && x1 != other.x1 && y1 != other.y1 && z1 != other.z1;
}

D1::~D1()
{
	cout << "D1: destructor" << endl;
}

istream& operator>>(istream& in, D1& ob)
{
	in >> (B1&)ob;
	cout << " x1 -> "; in >> ob.x1;
	cout << " y1 -> "; in >> ob.y1;
	cout << " z1 -> "; in >> ob.z1;
	return in;
}

ostream& operator<<(ostream& out, const D1& ob)
{
	out << (B1&)ob;
	out << " x1 = " << ob.x1 << ", y1 = " << ob.y1 << ", z1 = " << ob.z1 << endl;
	return out;
}
