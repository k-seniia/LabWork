#pragma once
#include <iostream>
#include <thread>
using namespace std;
class Food
{
protected:
	string name;
	double weight;
	double price;
	int calories;
public:
	Food(const string& name = "", const double& weight = 0.0, const double& price = 0.0, const int& calories = 0);
	Food(const Food& other);

	virtual void ToPrint() const;

	friend istream& operator>>(istream& in, Food& ob);
	friend ostream& operator<<(ostream& out, const Food& ob);

	virtual void cook() = 0;

	virtual ~Food();
};

