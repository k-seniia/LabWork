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