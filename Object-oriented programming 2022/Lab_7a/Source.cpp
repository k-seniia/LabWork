#include "Header.h"
#include <cassert>

TEXT::TEXT(string s) :s(s) {}

void TEXT::show() { cout << s << endl; }

ostream& operator<<(ostream& out, const TEXT& ob){
	for (int i = 0; i < size(ob.s); i++) {
		if (ob.s[i] >= 48 && ob.s[i] <= 57 || ob.s[i] >= 65 && ob.s[i] <= 90)
			continue;
		else
			out << ob.s[i];
	}
	out << endl;
	return out;
}
istream& operator>>(istream& in, const TEXT& ob) {
	in >> ob.s;
	return in;
}
