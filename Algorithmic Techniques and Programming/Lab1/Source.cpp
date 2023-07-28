#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

	double x{}, n{}, z{}, y{};

	for (x = 3; x <= 21; x += 0.62) {
		for (n = -5; n <= 1; n += 0.5) {

			z = ((1 + sqrt(abs(1 - x))) / (x * x - 1 + sqrt(1 + x))
				+ (1 - sqrt(1 + x)) / (1 + x * x - sqrt(1 + x)))
				/ ((sqrt(abs(1 - x)) - sqrt(1 + x)) / (sqrt(x * x - 1)));

			y = pow(z, 3) - n * n - 8 / (abs(pow(z, 3) - n * n) + 6);

			int w{};
			if (n < 0) { if (n == (int)n) w = 20; else w = 18; }
			else { if (n == (int)n) w = 21;	else w = 19; }
			cout << "x = " << x << "\tn = " << n;
			cout << setw(w) << "Z = " << z << "\ty = " << y << endl << endl;
		}
		cin.get();
	}

	return 0;
}

//if (sqrt(x * x - 1) == 0 || (sqrt(abs(1 - x)) - sqrt(1 + x)) / (sqrt(x * x - 1)) == 0 || 1 + x * x - sqrt(1 + x) == 0 || x * x - 1 + sqrt(1 + x) == 0) {
//	cout << "ERROR - ділення на 0" << endl; continue;
//}
//else if (1 + x < 0 || sqrt(x * x - 1) < 0) {
//	cout << "ERROR - область визначення квадратного кореня -> x>=0" << endl; continue;
//}
//else {
//	z = ((1 + sqrt(abs(1 - x))) / (x * x - 1 + sqrt(1 + x))
//		+ (1 - sqrt(1 + x)) / (1 + x * x - sqrt(1 + x)))
//		/ ((sqrt(abs(1 - x)) - sqrt(1 + x)) / (sqrt(x * x - 1)));
//
//	if (abs(pow(z, 3) - n * n) + 6 == 0) {
//		cout << "ERROR - ділення на 0" << endl; continue;
//	}
//	else {
//		y = pow(z, 3) - n * n - 8 / (abs(pow(z, 3) - n * n) + 6);
//
//		if (n < 0) { if (n == (int)n) w = 20; else w = 18; }
//		else { if (n == (int)n) w = 21;	else w = 19; }
//		cout << "x = " << x << "\tn = " << n;
//		cout << setw(w) << "Z = " << z << "\ty = " << y << endl << endl;
//	}
//}