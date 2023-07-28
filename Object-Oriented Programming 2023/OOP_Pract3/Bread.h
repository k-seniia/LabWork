#pragma once
#include "Food.h"
class Bread :
	public Food
{
	string type;
public:
	Bread();
	Bread(const string& type, const double& weight, const double& price, const int& calories);
	Bread(const Bread& other);

	void ToPrint() const override;

	void cook() override;

	friend istream& operator>>(istream& in, Bread& ob);
	friend ostream& operator<<(ostream& out, const Bread& ob);

	~Bread();
};

