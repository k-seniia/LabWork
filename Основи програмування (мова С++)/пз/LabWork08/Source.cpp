#pragma region Includes
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
#pragma endregion

int main() {
	cout << setprecision(3);
	
	const int S = 9; int i{}, j{};
	const double A = 0.75, B = 4.5, Hb = 0.5;
	double x[S]{}, z[S]{};
	for (double b = -1.5; b <= 2.5; b += Hb)
		x[i++] = (-B * cos(b)) / A;
	for (int k = 0; k < i; k++) {
		cout << "X[" << k << "] = " << x[k];
		if (x[k] > 0) {
			z[j] = sqrt(1 + x[k]);
			cout << "\tZ[" << j << "] = " << z[j];
			j++;
		}
		cout << endl;
	}
	
	return EXIT_SUCCESS;
}