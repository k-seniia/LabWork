#pragma once
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

class PERSON {
	string name;
	int age;
public:
	PERSON();
	PERSON(const string& name);
	PERSON(const int& age);
	PERSON(const string& name, const int& age);

	string get_name() const;
	int get_age() const;

	friend bool operator<(const PERSON& ob1, const PERSON& ob2);
	bool operator()(const PERSON& ob1, const PERSON& ob2) const;
};

class STAFF {
public:
	//insert
	void print_PERSON();
	void print_name();
	void print_age();

	void delete_name();
	void find();
};