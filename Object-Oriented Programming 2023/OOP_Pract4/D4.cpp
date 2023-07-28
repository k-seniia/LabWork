#include "D4.h"

D4::D4(const int& a, const int& b, const int& c, const double& x, const double& y, const double& z)
	:x4(x * 2), y4(y * 2), z4(z * 2), B2(a, b, c), D1(a, b, c, x, y, z)
{
	cout << "D4: initialization constructor (default)" << endl;
}

D4::D4(const int& a, const int& b, const int& c, const double& x, const double& y, const double& z, const B2& ob)
	:x4(x * 2), y4(y * 2), z4(z * 2), B2(ob), D1(a, b, c, x, y, z)
{
	cout << "D4: initialization/copy constructor" << endl;
}

D4::D4(const int& a, const int& b, const int& c, const double& x, const double& y, const double& z, const D1& ob)
	:x4(x * 2), y4(y * 2), z4(z * 2), B2(a, b, c), D1(ob)
{
	cout << "D4: initialization/copy constructor" << endl;
}

D4::D4(const double& x, const double& y, const double& z, const B2& ob1, const D1& ob2)
	:x4(x * 2), y4(y * 2), z4(z * 2), B2(ob1), D1(ob2)
{
	cout << "D4: initialization/copy constructor" << endl;
}

D4::D4(const D4& ob) 
	:x4(ob.x4), y4(ob.y4), z4(ob.z4), B2(ob), D1(ob)
{
	cout << "D4: copy constructor" << endl;
}

void D4::set_D4(const int& a, const int& b, const int& c, const double& x, const double& y, const double& z)
{
	set_B2(a * 2, b * 2, c * 2);
	set_D1(a, b, c, x, y, z);
	x4 = x * 2;
	y4 = y * 2;
	z4 = z * 2;
}

void D4::set_x4(const double& x)
{
	x4 = x * 2;
}

void D4::set_y4(const double& y)
{
	y4 = y * 2;
}

void D4::set_z4(const double& z)
{
	z4 = z * 2;
}

double D4::get_x4() const
{
	return x4;
}

double D4::get_y4() const
{
	return y4;
}

double D4::get_z4() const
{
	return z4;
}

D4::~D4()
{
	cout << "D4: destructor" << endl;
}

istream& operator>>(istream& in, D4& ob)
{
	in >> (B2&)ob;
	in >> (D1&)ob;
	cout << " x4 -> "; in >> ob.x4;
	cout << " y4 -> "; in >> ob.y4;
	cout << " z4 -> "; in >> ob.z4;
	return in;
}

ostream& operator<<(ostream& out, const D4& ob)
{
	out << (B2&)ob;
	out << (D1&)ob;
	out << " x4 = " << ob.x4 << ", y4 = " << ob.y4 << ", z4 = " << ob.z4 << endl;
	return out;
}
