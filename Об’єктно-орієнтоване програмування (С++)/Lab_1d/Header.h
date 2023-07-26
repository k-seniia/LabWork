#pragma once
#include <iostream>
#include <math.h>
#include <vector>
//#include <string>
using namespace std;

class Dog {
	string name;
	int weight;
	int age;

public:
	Dog();
	Dog(const string& n, const int& w, const int& a);
	Dog(const Dog& dog);

	void set_Dog(const string& n, const int& w, const int& a);
	void set_Dog(const Dog& dog);
	void set_name(const string& n);
	void set_weight(const int w);
	void set_age(const int a);

	string get_name()const;
	int get_weight()const;
	int get_age()const;

	Dog operator=(const Dog& dog);

	void show_dog()const;
};

class Master {
	string fullName;
	int id;
	//int size = 10;
	//Dog *dogs = new Dog[size];
	vector <Dog> dogs;
	static int count;

public:
	Master();
	Master(const string& fN, const int& id0);
	Master(const string& fN, const int& id0, const string& n, const int& w, const int& a);
	Master(const string& fN, const int& id0, const Dog& dog);

	void set_Master(const string& fN, const int& id0, const string& n, const int& w, const int& a);
	void set_Master(const string& fN, const int& id0, const Dog& dog);
	void set_Master(const string& fN, const int& id0);
	void set_fullName(const string& fN);
	void set_id(const int& id0);
	void set_dog(const string& n, const int& w, const int& a, const int& i);
	void set_dog(const Dog& dog, const int& i);

	void add_dog(const string& n, const int& w, const int& a);
	void add_dog(const Dog& dog);

	string get_fullName()const;
	int get_id()const;
	int get_count()const;

	void show_Master()const;
};
