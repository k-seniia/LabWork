#pragma once
#include "Food.h"
class Meat :
	public Food
{
protected:
	string type;
public:
	Meat();
	Meat(const string& type, const double& weight, const double& price, const int& calories);
	Meat(const Meat& other);

	void ToPrint() const override;

	void cook() override;

	friend istream& operator>>(istream& in, Meat& ob);
	friend ostream& operator<<(ostream& out, const Meat& ob);

	~Meat() {}
};

