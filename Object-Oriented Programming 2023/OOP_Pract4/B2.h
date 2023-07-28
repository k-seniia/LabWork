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