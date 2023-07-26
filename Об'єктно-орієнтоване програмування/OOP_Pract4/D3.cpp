#include "D3.h"

D3::D3(const int& a, const int& b, const int& c, const double& x, const double& y, const double& z) 
	:x3(x * 2), y3(y * 2), z3(z * 2), D1(a, b, c, x, y, z)
{
	cout << "D3: initialization constructor (default)" << endl;
}

D3::D3(const double& x, const double& y, const double& z, const D1& ob) 
	:x3(x * 2), y3(y * 2), z3(z * 2), D1(ob)
{
	cout << "D3: initialization/copy constructor" << endl;
}

D3::D3(const D3& ob) 
	:x3(ob.x3), y3(ob.y3), z3(ob.z3), D1(ob)
{
	cout << "D3: copy constructor" << endl;
}

void D3::set_D3(const int& a, const int& b, const int& c, const double& x, const double& y, const double& z)
{
	set_D1(a, b, c, x, y, z);
	x3 = x * 2;
	y3 = y * 2;
	z3 = z * 2;
}

void D3::set_x3(const double& x)
{
	x3 = x * 2;
}

void D3::set_y3(const double& y)
{
	y3 = y * 2;
}

void D3::set_z3(const double& z)
{
	z3 = z * 2;
}

double D3::get_x3() const
{
	return x3;
}

double D3::get_y3() const
{
	return y3;
}

double D3::get_z3() const
{
	return z3;
}

D3::~D3()
{
	cout << "D3: destructor" << endl;
}

istream& operator>>(istream& in, D3& ob)
{
	in >> (D1&)ob;
	cout << " x3 -> "; in >> ob.x3;
	cout << " y3 -> "; in >> ob.y3;
	cout << " z3 -> "; in >> ob.z3;
	return in;
}

ostream& operator<<(ostream& out, const D3& ob)
{
	out << (D1&)ob;
	out << " x3 = " << ob.x3 << ", y3 = " << ob.y3 << ", z3 = " << ob.z3 << endl;
	return out;
}
