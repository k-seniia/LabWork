#include <iostream>
#include "Header.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	SOBAKA sob1(5,12);
	cout << sob1 << endl;
	sob1.golos();

	cout << endl;

	SPANIEL sp1;
	sp1.set_sp(sob1, "black");
	sp1.set_w(11);
	cout << sp1 << endl;
	sp1.golos();
	
	cout << endl;

	SPANIEL sp2(7, 2, "white");
	cout << sp2 << endl;
	sp2.SOBAKA::golos();


	cout << "\n\n\n\n\n";
	return 0;
}