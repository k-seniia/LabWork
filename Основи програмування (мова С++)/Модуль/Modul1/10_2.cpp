#include <iostream>
#include <iomanip>

using namespace std;

#define DEBUG

int main() {
	srand(time(NULL));

	double l, r, s;
	const double PI = 3.14;

	cout << "L -> ";
#ifdef DEBUG
	cin >> l;
#else
	l = rand() % 20 - 10;
	cout << l << endl;
#endif // DEBUG

	if (l <= 0) {
		cout << "Error\n\n";
	}
	else {
		r = l / (2 * PI);	// L=2*PI*R	-> R=L/(2*PI)
		s = PI * r * r;		// S=PI*R*R

		cout << "R = " << r << endl;
		cout << "S = " << s << endl << endl;
	}

	return 0;
}