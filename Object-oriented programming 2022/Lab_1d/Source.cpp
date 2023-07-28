#include "Header.h"

Dog::Dog() : name("0"), weight(0), age(0) {}
Dog::Dog(const string& n, const int& w, const int& a) : name(n), weight(w), age(a) {}
Dog::Dog(const Dog& dog) : name(dog.name), weight(dog.weight), age(dog.age) {}

void Dog::set_Dog(const string& n, const int& w, const int& a) { name = n; weight = w; age = a; }
void Dog::set_Dog(const Dog& dog) { name = dog.name; weight = dog.weight; age = dog.age; }
void Dog::set_name(const string& n) { name = n; }
void Dog::set_weight(const int w) { weight = w; }
void Dog::set_age(const int a) { age = a; }

string Dog::get_name()const { return name; }
int Dog::get_weight()const { return weight; }
int Dog::get_age()const { return age; }

Dog Dog::operator=(const Dog& dog) {
	name = dog.name;	weight = dog.weight;	age = dog.age;
	return *this;
}

void Dog::show_dog()const { 
	if (name != "0")
		cout << "Dog's name: " << name << "\t Weight: " << weight << "\t Age: " << age << endl;
}

///////////////////////////////////////////////////////////////////////////////////////

int Master::count = 0;

Master::Master() : id(0) {
	cout << "\nthe number of Masters: " << ++count << "\n\n";
	fullName = "Master";
	dogs.push_back(Dog());
}
Master::Master(const string& fN, const int& id0): fullName(fN), id(id0) {
	cout << "\nthe number of Masters: " << ++count << "\n\n";
	dogs.push_back(Dog());
}
Master::Master(const string& fN, const int& id0, const string& n, const int& w, const int& a) : fullName(fN), id(id0) {
	cout << "\nthe number of Masters: " << ++count << "\n\n";
	//dogs[0].set_name(n);	dogs[0].set_weight(w);	dogs[0].set_age(a);
	dogs.push_back(Dog(n, w, a));
}
Master::Master(const string& fN, const int& id0, const Dog& dog) : fullName(fN), id(id0) {
	cout << "\nthe number of Masters: " << ++count << "\n\n";
	//dogs[0] = dog;
	dogs.push_back(Dog(dog));
}

void Master::set_Master(const string& fN, const int& id0, const string& n, const int& w, const int& a) { 
	fullName = fN;	id = id0; 
	//dogs[0].set_name(n);	dogs[0].set_weight(w);	dogs[0].set_age(a);
	dogs.push_back(Dog(n, w, a));
}
void Master::set_Master(const string& fN, const int& id0, const Dog& dog){
	fullName = fN;	id = id0;
	//dogs[0] = dog;
	dogs.push_back(Dog(dog));
}
void Master::set_Master(const string& fN, const int& id0) { fullName = fN;	id = id0; }
void Master::set_fullName(const string& fN) { fullName = fN; }
void Master::set_id(const int& id0) { id = id0; }
void Master::set_dog(const string& n, const int& w, const int& a, const int& i) { 
	//dogs[i-1].set_name(n);	dogs[i-1].set_weight(w);	dogs[i-1].set_age(a);
	dogs[i - 1].set_Dog(n, w, a);
}
void Master::set_dog(const Dog& dog, const int& i) { 
	//dogs[i-1] = dog;
	dogs[i - 1].set_Dog(dog);
}

void Master::add_dog(const string& n, const int& w, const int& a/*, const int& i*/){
	//size++;
	/*for (int i = 0; i < size; i++) {
		if (dogs[i].get_name() == "0") {
			dogs[i].set_name(n);		dogs[i].set_weight(w);	dogs[i].set_age(a);
			break;
		}
	}*/
	dogs.push_back(Dog(n, w, a));
}
void Master::add_dog(const Dog& dog/*, const int& i*/){
	//size++;
	//for (int i = 0; i < size; i++) {
	//	if (dogs[i].get_name() == "0") {
	//		dogs[i] = dog;
	//		break;
	//	}
	//}
	dogs.push_back(Dog(dog));
}

string Master::get_fullName()const { return fullName; }
int Master::get_id()const { return id; }
int Master::get_count()const { return count; }

void Master::show_Master()const { 
	cout << "Master's name: " << fullName << "\t ID: " << id << endl;
	cout << "   " << fullName << "'s dogs:" << endl;
	/*for (int i = 0; i < size; i++) {
		if (dogs[i].get_name() != "0") {
			cout << "\t- ";
			dogs[i].show_dog();
		}
	}*/
	for (const auto& d : dogs)
		d.show_dog();
	cout << endl;
}