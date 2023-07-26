////////////////////////////////////B1.h///////////////////////////////////
#pragma once
#include <iostream>
using namespace std;

class B1
{
protected:
	int a1, b1, c1;
public:
	B1(const int& a = 0, const int& b = 0, const int& c = 0);
	B1(const B1& ob);

	void set_B1(const int& a, const int& b, const int& c);
	void set_a1(const int& a);
	void set_b1(const int& b);
	void set_c1(const int& c);

	int get_a1() const;
	int get_b1() const;
	int get_c1() const;

	B1& operator=(const B1& ob);
	bool operator!=(const B1& other) const;

	friend istream& operator>>(istream& in, B1& ob);
	friend ostream& operator<<(ostream& out, const B1& ob);

	~B1();
};

////////////////////////////////////////B1.cpp//////////////////////////////////////////
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

////////////////////////////////////B2.h///////////////////////////////////
#pragma once
#include <iostream>
using namespace std;

class B2
{
protected:
	int a2, b2, c2;
public:
	B2(const int& a = 0, const int& b = 0, const int& c = 0);
	B2(const B2& ob);

	void set_B2(const int& a, const int& b, const int& c);
	void set_a2(const int& a);
	void set_b2(const int& b);
	void set_c2(const int& c);

	int get_a2() const;
	int get_b2() const;
	int get_c2() const;

	friend istream& operator>>(istream& in, B2& ob);
	friend ostream& operator<<(ostream& out, const B2& ob);

	~B2();
};

////////////////////////////////////////B2.cpp//////////////////////////////////////////
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

////////////////////////////////////D1.h///////////////////////////////////
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

////////////////////////////////////////D1.cpp//////////////////////////////////////////
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

////////////////////////////////////D2.h///////////////////////////////////
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

////////////////////////////////////////D2.cpp//////////////////////////////////////////
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

////////////////////////////////////D3.h///////////////////////////////////
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

////////////////////////////////////////D3.cpp//////////////////////////////////////////
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

////////////////////////////////////D4.h///////////////////////////////////
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

////////////////////////////////////////D4.cpp//////////////////////////////////////////
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

//////////////////////////////////////main.cpp////////////////////////////////////////
#include "D2.h"
#include "D3.h"
#include "D4.h"

int main() {
	D1 d;
}