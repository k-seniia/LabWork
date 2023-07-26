#include <iostream>
#include "Header.h"
using namespace std;

int main() {

	Complex c1;
	cout << c1;
	//cout << c1.operator+(3);
	cout << operator+(c1, 3) << endl;

	c1 = c1 + 3;
	cout << c1 << endl;

	Complex c2(4, 2);
	cout << c2;
	//cout << c2.operator+(c1);
	cout << operator+(c1, c2) << endl;
	
	Complex c3;
	c3 = c1 + c2;
	cout << c3 << endl;

	cout << "c1 = " << c1 << "c2 = " << c2 << endl;
	c1 = c2;
	cout << "c1 = " << c1 << "c2 = " << c2 << endl;
	cout << "c3 = " << c3 << endl;
	cout << "c1 = " << c1.operator=(c3)<< "c3 = " << c3 << endl;

	//cout << "c1 = c2 ?- " << boolalpha << c1.operator==(c2) << endl;
	cout << "c1 = c3 ?- " << boolalpha << (c1 == c3) << endl;
	cout << "c2 = c3 ?- " << boolalpha << operator==(c2, c3) << endl << endl;

	Complex c4;
	cout << c4;
	cout << c4.operator()(5, 6) << c4(6, 5) << endl;


	Complex ob1(2, 2), ob2(10, 10);


	cout << "r + m = " << ob2[0];

	cout << "\n\n\n\n\n";
	return 0;
}