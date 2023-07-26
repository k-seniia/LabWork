#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Persona {
protected:
	string pib;		//п≥б
	int age;		//в≥к
public:
	Persona();
	Persona(const string& pib, const int& age);
	Persona(const Persona& ob);

	void set_Persona(const string& pib, const int& age);
	void set_Persona(const Persona& ob);
	void set_PIB(const string& pib);
	void set_age(const int& age);
	
	int get_age() const;

	virtual int who() const = 0;	//Prepod Ц 1, Student Ц 3, Zav_kaf Ц 2
	virtual int ask() const = 0;
	virtual void print() const;
	friend ostream& operator<<(ostream& out, const Persona& ob);
};

class Prepod : public Persona {
protected:
	string disc;	//дисципл≥на
	int stup;		//ступ≥нь (ктн Ц 1, дтн Ц 2, немаЇ Ц 0)
public:
	Prepod();
	Prepod(const string& disc, const int& stup);	// ?
	Prepod(const string& pib, const int& age, const string& disc, const int& stup);
	Prepod(const Persona& ob, const string& disc, const int& stup);
	Prepod(const Prepod& ob);
	
	void set_Prepod(const string& disc, const int& stup);
	void set_Prepod(const string& pib, const int& age, const string& disc, const int& stup);
	void set_Prepod(const Persona& ob, const string& disc, const int& stup);
	void set_Prepod(const Prepod& ob);
	void set_disc(const int& disc);
	void set_stup(const int& stup);
		
	virtual int who() const override;
	virtual int ask() const override;
	virtual void print() const override;
	friend ostream& operator<<(ostream& out, const Prepod& ob);
};

class Student : public Persona {
protected:
	int eval[5];	//оц≥нки
public:
	void set_eval(int *e);	//прир≥вн€нн€ масиву, €к параметру класа, до переданого у функц≥ю
	void set_eval(const int& e0, const int& e1, const int& e2, const int& e3, const int& e4);
	void set_eval(const Student& ob);
	
	Student();
	Student(int *e);	//передача масиву у конструктор класу через посиланн€	// ?
	Student(const int& e0, const int& e1, const int& e2, const int& e3, const int& e4);	//пр€ма ≥н≥ц≥ал≥зац≥€ масиву	// ?
	Student(const string& pib, const int& age, int *e);
	Student(const string& pib, const int& age, const int& e0, const int& e1, const int& e2, const int& e3, const int& e4);
	Student(const Persona& ob, int *e);
	Student(const Persona& ob, const int& e0, const int& e1, const int& e2, const int& e3, const int& e4);
	Student(const Student& ob);
	
	void set_Student(const string& pib, const int& age, int *e);
	void set_Student(const Persona& ob, int *e);
	void set_Student(const Student& ob);	//передача масиву, €к параметр обьекта, у функц≥ю 

	int& operator[](const int& i);
	void operator()(const int& i, const int ei);

	virtual int who() const override;
	virtual int ask() const override;
	virtual void print() const override;
	friend ostream& operator<<(ostream& out, const Student& ob);
};

class Zav_kaf : public Prepod {
protected:
	string pos;		//посада
public:
	Zav_kaf();
	Zav_kaf(const string& pos);	// ?
	Zav_kaf(const string& disc, const int& stup, const string& pos);	// ?
	Zav_kaf(const string& pib, const int& age, const string& disc, const int& stup, const string& pos);
	Zav_kaf(const Persona& ob, const string& disc, const int& stup, const string& pos);
	Zav_kaf(const Prepod& ob, const string& pos);
	Zav_kaf(const Zav_kaf& ob);
	
	void set_pos(const string& pos);
	void set_Zav_kaf(const string& disc, const int& stup, const string& pos);
	void set_Zav_kaf(const string& pib, const int& age, const string& disc, const int& stup, const string& pos);
	void set_Zav_kaf(const Persona& ob, const string& disc, const int& stup, const string& pos);
	void set_Zav_kaf(const Prepod& ob, const string& pos);
	void set_Zav_kaf(const Zav_kaf& ob);

	virtual int who() const override;
	virtual int ask() const override;
	virtual void print() const override;
	friend ostream& operator<<(ostream& out, const Zav_kaf& ob);
};

class VUZ {
	int size = 6;
	Persona** Shtat = new Persona* [size];
public:
	VUZ();
	VUZ(const Prepod& p1, const Prepod& p2, const Student& s1, const Student& s2, const Student& s3, const Zav_kaf& z1);

	void less() const;
	void debt() const;

	Persona* operator[](const int& i);
	void operator()(const int& i, const Prepod& ob);
	void operator()(const int& i, const Student& ob);
	void operator()(const int& i, const Zav_kaf& ob);

	friend ostream& operator<<(ostream& out, Persona* ob);
};