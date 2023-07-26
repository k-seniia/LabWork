#include "B2.h"

B2::B2(const int& a, const int& b, const int& c) 
	:a2(a), b2(b), c2(c)
{
	cout << "B2: initialization constructor (default)" << endl;
}

B2::B2(const B2& ob) 
	:a2(ob.a2), b2(ob.b2), c2(ob.c2)
{
	cout << "B2: copy constructor" << endl;
}

void B2::set_B2(const int& a, const int& b, const int& c)
{
	a2 = a;
	b2 = b;
	c2 = c;
}

void B2::set_a2(const int& a)
{
	a2 = a;
}

void B2::set_b2(const int& b)
{
	b2 = b;
}

void B2::set_c2(const int& c)
{
	c2 = c;
}

int B2::get_a2() const
{
	return a2;
}

int B2::get_b2() const
{
	return b2;
}

int B2::get_c2() const
{
	return c2;
}

B2::~B2()
{
	cout << "B2: destructor" << endl;
}

istream& operator>>(istream& in, B2& ob)
{
	cout << " a2 -> "; in >> ob.a2;
	cout << " b2 -> "; in >> ob.b2;
	cout << " c2 -> "; in >> ob.c2;
	return in;
}

ostream& operator<<(ostream& out, const B2& ob)
{
	out << " a2 = " << ob.a2 << ", b2 = " << ob.b2 << ", c2 = " << ob.c2 << endl;
	return out;
}
