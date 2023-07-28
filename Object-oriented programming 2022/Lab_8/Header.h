#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//template <class T>
//class MAS;
//
//template <class T>
//ostream& operator<<(ostream& out, const MAS<T>& ob);

template <class T>
class MAS {
	int size;
	T* mas = new T[size];
	int ind;
public:
	MAS();
	void fill(const int& ind);
	T sum();
	T SA();
	void print();

	T operator[](int ind);
	~MAS();
	
	//template <class TT>
	friend ostream& operator<<(ostream& out, const MAS<T>& ob) {
		if (sizeof(ob.mas[0]) == sizeof(int))
			for (int i = 0; i < ob.ind; i++)
				out << setw(4) << ob.mas[i];
		else if (sizeof(ob.mas[0]) == sizeof(double))
			for (int i = 0; i < ob.ind; i++)
				out << setw(5) << ob.mas[i];
		else if (sizeof(ob.mas[0]) == sizeof(char))
			for (int i = 0; i < ob.ind; i++)
				out << setw(3) << ob.mas[i];
		out << endl;
		return out;
	}
};