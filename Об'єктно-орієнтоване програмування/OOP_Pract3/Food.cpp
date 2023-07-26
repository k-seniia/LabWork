#include "Food.h"

Food::Food(const string& name, const double& weight, const double& price, const int& calories)
	: name(name), weight(weight), price(price), calories(calories)
{
}

Food::Food(const Food& other)
	: name(other.name), weight(other.weight), price(other.price), calories(other.calories)
{
}

void Food::ToPrint() const
{
	cout << "Name: " << name << endl;
	cout << "Weight: " << weight << "g" << endl;
	cout << "Price: " << price << endl;
	cout << "Calories: " << calories << endl;
}

Food::~Food()
{
}

istream& operator>>(istream& in, Food& ob)
{
	cout << "Enter name -> "; in >> ob.name;
	cout << "Enter weight -> "; in >> ob.weight;
	cout << "Enter price -> "; in >> ob.price;
	cout << "Enter calories -> "; in >> ob.calories;
	return in;
}

ostream& operator<<(ostream& out, const Food& ob)
{
	out << "Name: " << ob.name << endl;
	out << "Weight: " << ob.weight << "g" << endl;
	out << "Price: " << ob.price << endl;
	out << "Calories: " << ob.calories << endl;
	return out;
}
