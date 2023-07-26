////////////////////////////////////Food.h///////////////////////////////////
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

////////////////////////////////////////Food.cpp//////////////////////////////////////////
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

////////////////////////////////////Bread.h///////////////////////////////////
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

////////////////////////////////////////Bread.cpp//////////////////////////////////////////
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

////////////////////////////////////Meat.h///////////////////////////////////
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

////////////////////////////////////////Meat.cpp//////////////////////////////////////////
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

////////////////////////////////////Cutlet.h///////////////////////////////////
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

////////////////////////////////////////Cutlet.cpp//////////////////////////////////////////
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

////////////////////////////////////Printer.h///////////////////////////////////
#pragma once
#include "Cutlet.h"
class Printer
{
public:
	void Printing(Food* ob);
};

////////////////////////////////////////Printer.cpp//////////////////////////////////////////
#include "Printer.h"

void Printer::Printing(Food* ob)
{
	ob->ToPrint();
}

//////////////////////////////////////main.cpp////////////////////////////////////////
#include "Bread.h"
#include "Cutlet.h"
#include "Printer.h"

int main() {
	Food* food[3];

	food[0] = new Bread("White", 500, 7, 200);
	food[1] = new Meat("Beef", 1000, 5, 250);
	food[2] = new Cutlet("Classic Recipe", "Chicken", 200, 6, 300);

	Printer p;

	for (int i = 0; i < 3; i++) {
		p.Printing(food[i]);
		food[i]->cook();
		cout << endl;
	}

	for (int i = 0; i < 3; i++) {
		delete food[i];
	}

	cout << endl << "////////////////////////////" << endl << endl;

	Bread bread;
	Meat meat;
	Cutlet cutlet;

	cin >> bread;
	cout << endl << bread << endl;;

	cin >> meat;
	cout << endl << meat << endl;

	cin >> cutlet;
	cout << endl << cutlet << endl;

	return 0;
}