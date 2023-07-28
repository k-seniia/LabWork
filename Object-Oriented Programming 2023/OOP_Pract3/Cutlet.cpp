#include "Cutlet.h"

Cutlet::Cutlet()
	: recipe(""), Meat()
{
}

Cutlet::Cutlet(const string& recipe, const string& type, const double& weight, const double& price, const int& calories)
	: Meat(type, weight, price, calories), recipe(recipe)
{
}

Cutlet::Cutlet(const Cutlet& other) 
	: Meat(other), recipe(other.recipe)
{
}

void Cutlet::ToPrint() const
{
	cout << "Food Type: Cutlet" << endl;
	Meat::ToPrint();
	cout << "Recipe: " << recipe << endl;
}

void Cutlet::cook()
{
	cout << "\nFrying cutlet";
	for (int i = 0; i < 3; i++) {
		this_thread::sleep_for(chrono::milliseconds(500));
		cout << " .";
	}
	this_thread::sleep_for(chrono::milliseconds(500));
	cout << " Done!" << endl;
	this_thread::sleep_for(chrono::milliseconds(500));
}

Cutlet::~Cutlet()
{
}

istream& operator>>(istream& in, Cutlet& ob)
{
	cout << "\tCutlet" << endl; in >> (Meat&)ob;
	cout << "Enter cutlet recipe -> "; in >> ob.recipe;
	return in;
}

ostream& operator<<(ostream& out, const Cutlet& ob)
{
	out << "Food Type: Cutlet" << endl;
	out << (Meat&)ob;
	out << "Recipe: " << ob.recipe << endl;
	return out;
}
