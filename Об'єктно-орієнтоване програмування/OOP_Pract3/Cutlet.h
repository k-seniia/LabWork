#pragma once
#include "Meat.h"
class Cutlet :
	public Meat
{
	string recipe;
public:
	Cutlet();
	Cutlet(const string& recipe, const string& type, const double& weight, const double& price, const int& calories);
	Cutlet(const Cutlet& other);

	void ToPrint() const override;

	void cook() override;

	friend istream& operator>>(istream& in, Cutlet& ob);
	friend ostream& operator<<(ostream& out, const Cutlet& ob);

	~Cutlet();
};

