#include "Header.h"
#include <iomanip>
#include <cassert>

NAME::NAME() : name("-") {}
NAME::NAME(const string& name) : name(name) {}
NAME::NAME(const NAME& ob) : name(ob.name) {}

bool operator<(const NAME& l, const NAME& r) {
	return l.name < r.name;
}

string NAME::get_name() { return name; }

ostream& operator<<(ostream& out, const NAME& ob) {
	out << ob.name;
	return out;
}

//////////////////////////////////////////////

NUMBER::NUMBER() : num("0") {}
NUMBER::NUMBER(const string& num) : num(num) {}
NUMBER::NUMBER(const NUMBER& ob) : num(ob.num) {}

string NUMBER::get_num() { return num; }

ostream& operator<<(ostream& out, const NUMBER& ob) {
	out << ob.num;
	return out;
}