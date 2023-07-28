#include "Meat.h"

Meat::Meat()
	: type(""), Food()
{
}

Meat::Meat(const string& type, const double& weight, const double& price, const int& calories)
	: Food("Meat", weight, price, calories), type(type)
{
}

Meat::Meat(const Meat& other)
	: Food(other), type(other.type)
{
}

void Meat::ToPrint() const
{
	cout << "Food Type: Meat" << endl;
	Food::ToPrint();
	cout << "Meat Type: " << type << endl;
}

void Meat::cook()
{
	cout << "\nCooking meat";
	for (int i = 0; i < 3; i++) {
		this_thread::sleep_for(chrono::milliseconds(500));
		cout << " .";
	}
	this_thread::sleep_for(chrono::milliseconds(500));
	cout << " Done!" << endl;
	this_thread::sleep_for(chrono::milliseconds(500));
}

istream& operator>>(istream& in, Meat& ob)
{
	cout << "\tMeat" << endl; in >> (Food&)ob;
	cout << "Enter meat type -> "; in >> ob.type;
	return in;
}

ostream& operator<<(ostream& out, const Meat& ob)
{
	out << "Food Type: Meat" << endl;
	out << (Food&)ob;
	out << "Meat Type: " << ob.type << endl;
	return out;
}
