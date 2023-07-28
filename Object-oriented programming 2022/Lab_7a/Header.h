#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class TEXT {
	string s;
public:
	TEXT(string s);

	void show();

	friend ostream& operator<<(ostream& out, const TEXT& ob);
	friend istream& operator>>(istream& in, const TEXT& ob);
};