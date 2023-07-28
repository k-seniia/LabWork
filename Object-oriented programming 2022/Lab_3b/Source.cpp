#include "Header.h"
#include <cassert>

Persona::Persona() :pib("0"), age(0) {}
Persona::Persona(const string& pib, const int& age) :pib(pib), age(age) {}
Persona::Persona(const Persona& ob) :pib(ob.pib), age(ob.age) {}

void Persona::set_Persona(const string& pib, const int& age) { this->pib = pib; this->age = age; }
void Persona::set_Persona(const Persona& ob) { set_Persona(ob.pib, ob.age); }
void Persona::set_PIB(const string& pib) { this->pib = pib; }
void Persona::set_age(const int& age) { this->age = age; }

int Persona::get_age() const { return age; }

void Persona::print() const {
	cout << "ПIБ - " << pib << "\nВiк - " << age << endl;
}
ostream& operator<<(ostream& out, const Persona& ob) {
	out << "ПIБ - " << ob.pib << "\nВiк - " << ob.age << endl;
	return out;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------

Prepod::Prepod() :disc("0"), stup(0), Persona() {}
Prepod::Prepod(const string& disc, const int& stup) :disc(disc), stup(stup), Persona() {}
Prepod::Prepod(const string& pib, const int& age, const string& disc, const int& stup) :disc(disc), stup(stup), Persona(pib, age) {}
Prepod::Prepod(const Persona& ob, const string& disc, const int& stup) :disc(disc), stup(stup), Persona(ob) {}
Prepod::Prepod(const Prepod& ob) :disc(ob.disc), stup(ob.stup), Persona((Persona&)ob) {}

void Prepod::set_Prepod(const string& disc, const int& stup) { this->disc = disc; this->stup = stup; }
void Prepod::set_Prepod(const string& pib, const int& age, const string& disc, const int& stup) { set_Persona(pib, age); set_Prepod(disc, stup); }
void Prepod::set_Prepod(const Persona& ob, const string& disc, const int& stup) { set_Persona(ob); set_Prepod(disc, stup); }
void Prepod::set_Prepod(const Prepod& ob) { set_Persona((Persona&)ob); set_Prepod(ob.disc, ob.stup); }
void Prepod::set_disc(const int& disc) { this->disc = disc; }
void Prepod::set_stup(const int& stup) { this->stup = stup; }

int Prepod::who() const { return 1; }
int Prepod::ask() const { return stup; }
void Prepod::print() const {
	Persona::print();
	cout << "Дисциплiна - " << disc << "\nСтупiнь - ";
	if (stup== 1)
		cout << "кнт" << endl;
	else if (stup == 2)
		cout << "дтн" << endl;
	else if (stup == 0)
		cout << "немає" << endl;
}
ostream& operator<<(ostream& out, const Prepod& ob) {
	out << (Persona&)ob;
	out << "Дисциплiна - " << ob.disc << "\nСтупiнь - ";
	if (ob.stup == 1)
		out << "кнт" << endl;
	else if (ob.stup == 2)
		out << "дтн" << endl;
	else if (ob.stup == 0)
		out << "немає" << endl;
	return out;
}

// ---------------------------------------------------------------------------------------------------------------------------------------------------------

Student::Student() :Persona() {
	for (int i = 0; i < 5; i++) {
		eval[i] = 0;
	}
}
Student::Student(int *e) :Persona() { set_eval(e); }
Student::Student(const int& e0, const int& e1, const int& e2, const int& e3, const int& e4) :Persona() { set_eval(e0, e1, e2, e3, e4); }
Student::Student(const string& pib, const int& age, int *e) : Persona(pib, age) { set_eval(e); }
Student::Student(const string& pib, const int& age, const int& e0, const int& e1, const int& e2, const int& e3, const int& e4) : Persona(pib, age) { set_eval(e0, e1, e2, e3, e4); }
Student::Student(const Persona& ob, int *e) : Persona(ob) { set_eval(e); }
Student::Student(const Persona& ob, const int& e0, const int& e1, const int& e2, const int& e3, const int& e4) : Persona(ob) { set_eval(e0, e1, e2, e3, e4); }
Student::Student(const Student& ob) : Persona((Persona&)ob) { set_eval(ob); }

void Student::set_eval(const int& e0, const int& e1, const int& e2, const int& e3, const int& e4) {
	eval[0] = e0; eval[1] = e1; eval[2] = e2; eval[3] = e3; eval[4] = e4;
}
void Student::set_eval(int *e) {
	for (int i = 0; i < 5; i++) {
		eval[i] = e[i];
	}
}
void Student::set_eval(const Student& ob) {
	for (int i = 0; i < 5; i++) {
		eval[i] = ob.eval[i];
	}
}
void Student::set_Student(const string& pib, const int& age, int *e) { set_Persona(pib, age); set_eval(e); }
void Student::set_Student(const Persona& ob, int *e) { set_Persona(ob); set_eval(e); }
void Student::set_Student(const Student& ob) { set_Persona((Persona&)ob); set_eval(ob); }

int& Student::operator[](const int& i) {
	assert(i >= 0 && i < 5);
	return eval[i];
}
void Student::operator()(const int& i, const int ei) {
	assert(i >= 0 && i < 5);
	eval[i] = ei;
}

int Student::who() const { return 3; }
int Student::ask() const {
	int count{};
	for (int i = 0; i < 5; i++) {
		if (eval[i] == 2)
			count++;
	}
	return count;
}
void Student::print() const {
	Persona::print();
	cout << "Оцiнки -";
	for (int i = 0; i < 5; i++) {
		cout << setw(3) << eval[i];
	}
	cout << endl;
}
ostream& operator<<(ostream& out, const Student& ob) {
	out << (Persona&)ob;
	out << "Оцiнки -";
	for (int i = 0; i < 5; i++) {
		out << setw(3) << ob.eval[i];
	}
	out << endl;
	return out;
}

// ---------------------------------------------------------------------------------------------------------------------------------------------------------

Zav_kaf::Zav_kaf() :pos("0"), Prepod() {}
Zav_kaf::Zav_kaf(const string& pos) :pos(pos), Prepod() {}
Zav_kaf::Zav_kaf(const string& disc, const int& stup, const string& pos) :pos(pos), Prepod(disc, stup) {}
Zav_kaf::Zav_kaf(const string& pib, const int& age, const string& disc, const int& stup, const string& pos) : pos(pos), Prepod(pib, age, disc, stup) {}
Zav_kaf::Zav_kaf(const Persona& ob, const string& disc, const int& stup, const string& pos) :pos(pos), Prepod(ob, disc, stup) {}
Zav_kaf::Zav_kaf(const Prepod& ob, const string& pos) :pos(pos), Prepod(ob) {}
Zav_kaf::Zav_kaf(const Zav_kaf& ob) :pos(ob.pos), Prepod((Prepod&)ob) {}

void Zav_kaf::set_pos(const string& pos) { this->pos = pos; }
void Zav_kaf::set_Zav_kaf(const string& disc, const int& stup, const string& pos) { set_Prepod(disc, stup); set_pos(pos); }
void Zav_kaf::set_Zav_kaf(const string& pib, const int& age, const string& disc, const int& stup, const string& pos) { set_Prepod(pib, age, disc, stup); set_pos(pos); }
void Zav_kaf::set_Zav_kaf(const Persona& ob, const string& disc, const int& stup, const string& pos) { set_Prepod(ob, disc, stup); set_pos(pos); }
void Zav_kaf::set_Zav_kaf(const Prepod& ob, const string& pos) { set_Prepod(ob); set_pos(pos); }
void Zav_kaf::set_Zav_kaf(const Zav_kaf& ob) { set_Prepod((Prepod&)ob); set_pos(ob.pos); }

int Zav_kaf::who() const { return 2; }
int Zav_kaf::ask() const { return age; }
void Zav_kaf::print() const {
	Prepod::print();
	cout << "Посада - " << pos << endl;
}
ostream& operator<<(ostream& out, const Zav_kaf& ob) {
	out << (Prepod&)ob;
	out << "Посада - " << ob.pos << endl;
	return out;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------

VUZ::VUZ() {
	int s = size;
	while (s--)
		switch (s % 6) {
		case 0: Shtat[s] = new Prepod("Иванов", 25, "мат", 2); break;
		case 1: Shtat[s] = new Prepod("Петров", 55, "мат2", 1); break;
		case 2: {int mas1[5] = { 5,5,5,5,5 }; Shtat[s] = new Student("F1", 18, mas1); break; }
		case 3: Shtat[s] = new Student("F2", 18, 2, 5, 5, 2, 5); break;
		case 4: {int mas3[5] = { 5,2,2,5,2 }; Shtat[s] = new Student("F3", 18, mas3); break; }
		case 5: Shtat[s] = new Zav_kaf("Сидоров", 40, "мат3", 0, "пос"); break;
		}
}

VUZ::VUZ(const Prepod& p1, const Prepod& p2, const Student& s1, const Student& s2, const Student& s3, const Zav_kaf& z1) {
	int s = size;
	while (s--)
		switch (s % 6) {
		case 0: Shtat[s] = new Prepod(p1); break;
		case 1: Shtat[s] = new Prepod(p2); break;
		case 2: Shtat[s] = new Student(s1); break;
		case 3: Shtat[s] = new Student(s2); break;
		case 4: Shtat[s] = new Student(s3); break;
		case 5: Shtat[s] = new Zav_kaf(z1); break;
		}
}

Persona* VUZ::operator[](const int& i){
	assert(i >= 0 && i < size);
	/*if (Shtat[i]->who() == 1)
		cout << (Prepod&)*Shtat[i] << endl;
	if (Shtat[i]->who() == 2)
		cout << (Zav_kaf&)*Shtat[i] << endl;
	if (Shtat[i]->who() == 3)
		cout << (Student&)*Shtat[i] << endl;*/
	return Shtat[i];		
}
void VUZ::operator()(const int& i, const Prepod& ob) {
	assert(i >= 0 && i < size);
	Shtat[i] = new Prepod(ob);
}
void VUZ::operator()(const int& i, const Student& ob) {
	assert(i >= 0 && i < size);
	Shtat[i] = new Student(ob);
}
void VUZ::operator()(const int& i, const Zav_kaf& ob) {
	assert(i >= 0 && i < size);
	Shtat[i] = new Zav_kaf(ob);
}

void VUZ::less() const {
	for (int i = 0; i < 6; i++) {
		if (Shtat[i]->who() == 1 || Shtat[i]->who() == 2) {
			if (Shtat[i]->get_age() < 50) {
				if (Shtat[i]->who() == 1)
					cout << (Prepod&) *Shtat[i] << endl;
				if (Shtat[i]->who() == 2)
					cout << (Zav_kaf&) *Shtat[i] << endl;
				//Shtat[i]->print(); cout << endl;
			}
		}
	}
}
void VUZ::debt() const {
	for (int i = 0; i < 6; i++) {
		if (Shtat[i]->who() == 3 && Shtat[i]->ask() > 0) {
			cout << (Student&) *Shtat[i] << endl;
			//Shtat[i]->print(); cout << endl;
		}
	}
}

ostream& operator<<(ostream& out, Persona* ob) {
	if (ob->who() == 1)
		out << (Prepod&) *ob << endl;
	if (ob->who() == 2)
		out << (Zav_kaf&) *ob << endl;
	if (ob->who() == 0)
		out << (Student&) *ob << endl;
	return out;
}