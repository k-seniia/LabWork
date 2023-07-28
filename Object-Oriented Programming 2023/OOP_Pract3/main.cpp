#include "Bread.h"
#include "Cutlet.h"
#include "Printer.h"

int main() {
	Food* food[3];

	food[0] = new Bread("White", 500, 7, 200);
	food[1] = new Meat("Beef", 1000, 5, 250);
	food[2] = new Cutlet("Classic Recipe", "Chicken", 200, 6, 300);

	Printer p;

	for (int i = 0; i < 3; i++) {
		p.Printing(food[i]);
		food[i]->cook();
		cout << endl;
	}

	for (int i = 0; i < 3; i++) {
		delete food[i];
	}

	cout << endl << "////////////////////////////" << endl << endl;

	Bread bread;
	Meat meat;
	Cutlet cutlet;

	cin >> bread;
	cout << endl << bread << endl;;

	cin >> meat;
	cout << endl << meat << endl;

	cin >> cutlet;
	cout << endl << cutlet << endl;

	return 0;
}