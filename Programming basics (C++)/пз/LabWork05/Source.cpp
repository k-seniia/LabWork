#pragma region Includes
#include <iostream>
#include <math.h>
#include <iomanip>
#include <locale>
#include "windows.h"
using namespace std;
#pragma endregion
	 
double arythmetical_equatation(double a, double x, double b);
bool logical_expression(bool A, bool B, bool C, double X, double Y);
bool graphical_region(double X, double Y);

#define DEBUG

int main() {
#pragma region Ukranian
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Ukrainian");
#pragma endregion
	
//Task 1
	cout << "\tTask 1\n" << endl;

	double a{}, x{}, b{};
#ifdef DEBUG
	a = 0.5; x = 3.4; b = 1.65;
	cout << "a = " << a;
	cout << "\tx = " << x;
	cout << "\tb = " << b << endl;
#else
	cout << "a -> "; cin >> a;
	cout << "x -> "; cin >> x;
	cout << "b -> "; cin >> b;
#endif // DEBUG

	cout << "\ny = " << fixed << setprecision(3) << arythmetical_equatation(a, x, b) << defaultfloat << endl;

// Task 2
	cout << "\n\tTask 2\n" << endl;

	bool A, B, C;
	double X, Y;
#ifdef DEBUG
	A = true; B = true; C = false;
	X = 1.5; Y = 2.5;
	cout << "A = " << A << "\tB = " << B << "\tC = " << C << endl;
	cout << "X = " << X << "   Y = " << Y << endl;
#else
	cout << "A -> "; cin >> A;
	cout << "B -> "; cin >> B;
	cout << "C -> "; cin >> C;
	cout << "X -> "; cin >> X;
	cout << "Y -> "; cin >> Y;
#endif // DEBUG

	cout << "\nz = " << boolalpha << logical_expression(A, B, C, X, Y) << endl;

//Task 3
	cout << "\n\tTask 3\n" << endl;

#ifdef DEBUG
	cout << "X = " << X;
	cout << "\tY = " << Y << endl;
#else
	cout << "X -> "; cin >> X;
	cout << "Y -> "; cin >> Y;
#endif // DEBUG

	cout << "\nВходить у ОДЗ? - " << graphical_region(X, Y) << endl;
	
	cout << endl << endl;
	system("pause");
	return EXIT_SUCCESS;
}



double arythmetical_equatation(double a, double x, double b) {

	double y = (log10(pow(x + 1, 2)) + 1.5 * pow(x, 3) + pow((x + 0.6 * 1e3), 1.0 / 3))
												/
			      (pow(x, 5) + 1.25 * 1e-2 * sin(pow(b, 2)) + pow(a + 0.6, 1.0 / 3));

	return y;
}

bool logical_expression(bool A, bool B, bool C, double X, double Y) {

	bool z = A && B || C || !(X <= Y || X > -0.15);
	//у випадку стандартних значень
	//z = True && True || False || !(True || True);
	//									   ^
	//z = True && True || False || !(True);
	//							   ^
	//z = True && True || False || False;
	//		    ^
	//z =	  True	   || False || False;
	//				    ^1		 ^2
	//z = True;

	return z;
}

bool graphical_region(double X, double Y) {

	if ((X * Y) <= 0 && X <= 3 && Y <= 3)	//true якщо або Х<=0 або Y<=0
		return 1;
	else
		return 0;
}