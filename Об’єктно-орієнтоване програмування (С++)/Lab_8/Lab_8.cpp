#include <iostream>
#include <iomanip>
#include "Header.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	MAS<int> ob;
	int ind = rand() % 95 + 5;
	cout << "Загальна кiлькiсть елементiв -> " << ind << endl;
	for (int i = 0; i <= ind; i++)
		ob.fill(i);
	//ob.print();
	cout << ob;
	
	cout <<"sum = "<< ob.sum() << endl;
	cout <<"середньоарифметичне = "<< ob.SA() << endl;
	
	int il = rand() % ++ind;
	cout << "max = " << ob.operator[](il) << " -> з " << il << " перших елементiв" << endl;


	cout << "\n\n\n\n\n";


	MAS<double> ob1;
	int ind1 = rand() % 95 + 5;
	cout << "Загальна кiлькiсть елементiв -> " << ind1 << endl;
	for (int i = 0; i <= ind1; i++)
		ob1.fill(i);
	//ob1.print();
	cout << ob1;

	cout << "sum = " << ob1.sum() << endl;

	cout << "середньоарифметичне = " << ob1.SA() << endl;

	int il1 = rand() % ++ind1;
	cout << "max = " << ob1[il1] << " -> з " << il1 << " перших елементiв" << endl;


	cout << "\n\n\n\n\n";


	MAS<char> ob2;
	int ind2 = rand() % 95 + 5;
	cout << "Загальна кiлькiсть елементiв -> " << ind2 << endl;
	for (int i = 0; i <= ind2; i++)
		ob2.fill(i);
	//ob2.print();
	cout << ob2;

	cout << "sum = '" << ob2.sum() << "'" << endl;

	cout << "середньоарифметичне = '" << ob2.SA() << "'" << endl;

	int il2 = rand() % ++ind2;
	cout << "max = '" << ob2[il2] << "' -> з " << il2 << " перших елементiв" << endl;



	cout << "\n\n\n\n\n";
	return 0;
}