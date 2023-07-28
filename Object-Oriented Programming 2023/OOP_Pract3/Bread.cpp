#include "Bread.h"

Bread::Bread() 
	: type(""), Food()
{
}

Bread::Bread(const string& type, const double& weight, const double& price, const int& calories)
	: Food("Bread", weight, price, calories), type(type)
{
}

Bread::Bread(const Bread& other)
	: Food(other), type(other.type)
{
}

void Bread::ToPrint() const
{
	cout << "Food Type: Bread" << endl;
	Food::ToPrint();
	cout << "Bread Type: " << type << endl;
}

void Bread::cook()
{
	cout << "\nBaking bread";
	for (int i = 0; i < 3; i++) {
		this_thread::sleep_for(chrono::milliseconds(500));
		cout << " .";
	}
	this_thread::sleep_for(chrono::milliseconds(500));
	cout << " Done!" << endl;
	this_thread::sleep_for(chrono::milliseconds(500));
}

Bread::~Bread()
{
}

istream& operator>>(istream& in, Bread& ob)
{
	cout << "\tBread" << endl; in >> (Food&)ob;
	cout << "Enter bread type -> "; in >> ob.type;
	return in;
}

ostream& operator<<(ostream& out, const Bread& ob)
{
	out << "Food Type: Bread" << endl;
	out << (Food&)ob;
	out << "Bread Type: " << ob.type << endl;
	return out;
}
