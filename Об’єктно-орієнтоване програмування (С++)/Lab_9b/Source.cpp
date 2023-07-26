#include "Header.h"
#include <iomanip>
#include <cassert>

PERSON::PERSON() :name("0"), age(0) {}
PERSON::PERSON(const string& name) :name(name) {}
PERSON::PERSON(const int& age) :age(age) {}
PERSON::PERSON(const string& name, const int& age): name(name), age(age) {}

string PERSON::get_name() const { return name; }
int PERSON::get_age() const { return age; }

bool operator<(const PERSON& ob1, const PERSON& ob2) { 
	return ob1.name < ob2.name; 
}
bool PERSON::operator()(const PERSON& ob1, const PERSON& ob2) const{
	return ob1.age < ob2.age;
}