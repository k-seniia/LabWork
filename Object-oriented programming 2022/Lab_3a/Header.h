#pragma once
#include <iostream>

using namespace std;

class SOBAKA {
protected:
	int weight;
	int age;
public:
	SOBAKA();
	SOBAKA(const int& w, const int& a);

	void set_sob(const SOBAKA& ob);
	void set_sob(const int& w, const int& a);
	void set_w(const int& w);
	void set_a(const int& a);

	void golos()const;

	friend ostream& operator<<(ostream& out, const SOBAKA& ob);

	~SOBAKA();
};

class SPANIEL : public SOBAKA {
	string color;
public:
	SPANIEL();
	SPANIEL(const SOBAKA& ob, const string& c);
	SPANIEL(const int& w, const int& a, const string& c);

	void set_sp(const SOBAKA& ob, const string& c);
	void set_sp(const int& w, const int& a, const string& c);
	void set_c(const string& c);

	void golos()const;

	friend ostream& operator<<(ostream& out, const SPANIEL& ob);

	~SPANIEL();
};