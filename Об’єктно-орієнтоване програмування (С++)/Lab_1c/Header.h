#pragma once
#include <iostream>
#include <math.h>
using namespace std;

class Complex {
	int r;
	int m;

public:
	Complex(const int& r0=0, const int& m0=0);
	Complex(const Complex& ob);
	
	/*Complex operator+(const Complex& ob);
	Complex operator+(const int& a);*/
	Complex operator=(const Complex& ob);
	//bool operator==(const Complex& ob);
	Complex operator()(const int& r0, const int& m0);
	//int operator[](const Complex& ob);
	int operator[](int a);

	friend Complex operator+(const Complex& ob1, const Complex& ob2);
	friend Complex operator+(const Complex& ob, const int& a);
	friend bool operator==(const Complex& ob1, const Complex& ob2);

	friend ostream& operator << (ostream& out, const Complex& ob);
};
