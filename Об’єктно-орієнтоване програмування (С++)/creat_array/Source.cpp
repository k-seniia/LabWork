#include <iostream>
#include <stdio.h>

using namespace std;

class Car {
    string fname;
public:
    Car(string aname) { this->fname = aname; }
    string GetName(void) { return fname; }
    void SetName(string ANew) { fname = ANew; }
    void Print(void) { printf(" # %s\n", fname.c_str()); }
};

class Bus : public Car {
public:
    Bus(string aname) : Car(aname) {};
};

class Truck : public Car {
public:
    Truck(string aname) : Car(aname) {};
};

class Passenger : public Car {
public:
    Passenger(string aname) : Car(aname) {};
};

Car** create_array(unsigned size) {
    const int maxSize = size;
    Car** cars = new Car * [maxSize];

    while (size--)
        switch (size % 4) {
        case 0:  cars[size] = new Car("Запорожец");  break;
        case 1:  cars[size] = new Bus("Маршрутка Газель"); break;
        case 2:  cars[size] = new Truck("Камаз"); break;
        case 3:  cars[size] = new Passenger("Водятел"); break;
        }

    return cars;
}

//VUZ** arr(const Prepod& p1, const Prepod& p2, const Student& s1, const Student& s2, const Student& s3, const Zav_kaf& z1) {
//    int size = 6;
//    Persona** Shtat = new Prepod * [6];
//
//    while (size--)
//        switch (size % 6) {
//        case 0: Shtat[size] = new Prepod(p1); break;
//        case 1: Shtat[size] = new Prepod(p2); break;
//        case 2: Shtat[size] = new Student(s1); break;
//        case 3: Shtat[size] = new Student(s2); break;
//        case 4: Shtat[size] = new Student(s3); break;
//        case 5: Shtat[size] = new Zav_kaf(z1); break;
//        }
//    return Shtat;
//}