#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class NAME {
	string name;
public:
	NAME();
	NAME(const string& name);
	NAME(const NAME& ob);

	friend bool operator<(const NAME& l, const NAME& r);

	string get_name();

	friend ostream& operator<<(ostream& out, const NAME& ob);
};

class NUMBER {
	string num;
public:
	NUMBER();
	NUMBER(const string& num);
	NUMBER(const NUMBER& ob);

	string get_num();

	friend ostream& operator<<(ostream& out, const NUMBER& ob);
};
