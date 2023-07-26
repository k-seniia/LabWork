#include "B1.h"

B1::B1(const int& a, const int& b, const int& c)
	:a1(a), b1(b), c1(c)
{
	cout << "B1: initialization constructor (default)" << endl;
}

B1::B1(const B1& ob)
	:a1(ob.a1), b1(ob.b1), c1(ob.c1)
{
	cout << "B1: copy constructor" << endl;
}

void B1::set_B1(const int& a, const int& b, const int& c)
{
	a1 = a;
	b1 = b;
	c1 = c;
}

void B1::set_a1(const int& a)
{
	a1 = a;
}

void B1::set_b1(const int& b)
{
	b1 = b;
}

void B1::set_c1(const int& c)
{
	c1 = c;
}

int B1::get_a1() const
{
	return a1;
}

int B1::get_b1() const
{
	return b1;
}

int B1::get_c1() const
{
	return c1;
}

B1& B1::operator=(const B1& ob)
{
	a1 = ob.a1;
	b1 = ob.b1;
	c1 = ob.c1;
	return *this;
}

bool B1::operator!=(const B1& other) const
{
	return a1 != other.a1 && b1 != other.b1 && c1 != other.c1;
}

B1::~B1()
{
	cout << "B1: destructor" << endl;
}

istream& operator>>(istream& in, B1& ob)
{
	cout << " a1 -> "; in >> ob.a1;
	cout << " b1 -> "; in >> ob.b1;
	cout << " c1 -> "; in >> ob.c1;
	return in;
}

ostream& operator<<(ostream& out, const B1& ob)
{
	out << " a1 = " << ob.a1 << ", b1 = " << ob.b1 << ", c1 = " << ob.c1 << endl;
	return out;
}
