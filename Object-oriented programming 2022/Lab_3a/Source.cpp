#include "Header.h"

SOBAKA::SOBAKA() : weight(0), age(0) { cout << "����������� SOBAKA" << endl; }
SOBAKA::SOBAKA(const int& w, const int& a) : weight(w), age(a) { cout << "����������� SOBAKA" << endl; }

void SOBAKA::set_sob(const SOBAKA& ob){ weight = ob.weight; age = ob.age; }
void SOBAKA::set_sob(const int& w, const int& a) { weight = w; age = a; }
void SOBAKA::set_w(const int& w){ weight = w; }
void SOBAKA::set_a(const int& a){ age = a; }

void SOBAKA::golos()const{
	if (weight >= 10)
		cout << "���" << endl;
	else
		cout << "���" << endl;
}

ostream& operator<<(ostream& out, const SOBAKA& ob){
	out << "weight = " << ob.weight << endl << "age = " << ob.age << endl;
	return out;
}

SOBAKA::~SOBAKA() { cout << "���������� SOBAKA" << endl; }

//---------------------------------------------------------------------------------------------------------------

SPANIEL::SPANIEL() : color("0") { 
	set_sob(0, 0);
	cout << "����������� SPANIEL" << endl << endl;
}
SPANIEL::SPANIEL(const SOBAKA& ob, const string& c) : color(c) { cout << "����������� SPANIEL" << endl << endl; }
SPANIEL::SPANIEL(const int& w, const int& a, const string& c) : color(c) {
	set_sob(w, a);
	cout << "����������� SPANIEL" << endl << endl;
}

void SPANIEL::set_sp(const SOBAKA& ob, const string& c) { color = c; set_sob(ob); }
void SPANIEL::set_sp(const int& w, const int& a, const string& c) { set_sob(w, a); color = c; }
void SPANIEL::set_c(const string& c){ color = c; }

void SPANIEL::golos()const{
	if (weight >= 10)
		cout << "��� ���" << endl;
	else
		cout << "��� ���" << endl;
}

ostream& operator<<(ostream& out, const SPANIEL& ob){
	out << (SOBAKA&)ob << "color - " << ob.color << endl;
	return out;
}

SPANIEL::~SPANIEL() { cout << "���������� SPANIEL" << endl; }