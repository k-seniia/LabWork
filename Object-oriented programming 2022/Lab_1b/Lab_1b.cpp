#include <iostream>
#include "Header.h"
using namespace std;

int main() {

	Figure c1(5);
	cout << "Square circle: " << c1.S_circle() << endl;


	Figure t1(4, 3, 6);
	cout << "Square triangle: " << t1.S_triangle() << endl;

	return 0;
}