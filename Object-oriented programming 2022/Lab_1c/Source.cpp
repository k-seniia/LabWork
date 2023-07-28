#include "Header.h"

Complex::Complex(const int& r0, const int& m0): r(r0), m(m0) {}
Complex::Complex(const Complex& ob): r(ob.r), m(ob.m) {}

//Complex Complex::operator+(const Complex& ob){
//	this->r += ob.r;
//	this->m += ob.m;
//	return *this;
//	/*Complex tempob;
//	tempob.r = this->r + ob.r;
//	tempob.m = this->m + ob.m;
//	return tempob;*/
//}
//Complex Complex::operator+(const int& a){
//	this->r += a;
//	this->m += a;
//	return *this;
//	/*Complex tempa;
//	tempa.r = this->r + a;
//	tempa.m = this->m + a;
//	return tempa;*/
//}
Complex Complex::operator=(const Complex& ob) {
	this->r = ob.r;
	this->m = ob.m;
	return *this;
}
//bool Complex::operator==(const Complex& ob) {
//	if (r == ob.r && m == ob.m) return true;
//	else return false;
//}
Complex Complex::operator()(const int& r0, const int& m0) {
	r = r0;	m = m0;
	return *this;
}
//int Complex::operator[](const Complex& ob) {
//	return ob.r + ob.m;
//}
int Complex::operator[](int a) {
	return r + m;
}

Complex operator+(const Complex& ob1, const Complex& ob2) {
	return Complex(ob1.r + ob2.r, ob1.m + ob2.m);
}
Complex operator+(const Complex& ob, const int& a) {
	return Complex(ob.r + a, ob.m + a);
}
bool operator==(const Complex& ob1, const Complex& ob2) {
	if (ob1.r == ob2.r && ob1.m == ob2.m) return true;
	else return false;
}

ostream& operator << (ostream& out, const Complex& ob) {
	cout << "Complex: " << ob.r << " + " << ob.m << "i" << endl;
	return out;
}