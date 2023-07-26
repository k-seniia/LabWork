#include <iostream>
#include "Header.h"
using namespace std;

//Створити клас Point(2 змінні х і у).Реалізувати функції класу :
//– Конструктор за умовчанням;
//– Конструктор з параметром;
//– Конструктор копіювання;
//– функція ініціалізації змінних х і у(set());
//– функція, яка повертає суму і добуток змінних(передача параметрів через посилання);
//– виведення результатів.


int main() {

	Point p1;
	p1.show();
	p1.set(10, 20);
	p1.show();

	cout << endl << "sum = " << p1.sum(p1) << endl << endl;

	Point p2(100, 200);
	p2.show();
	p2.set_x(50);
	p2.show();

	cout << endl << "multi = " << p2.multi(p2) << endl << endl;

	Point p3(p1);
	p3.show();
	p3.set_y(30);
	p3.show();

	cout << "\n\n\n\n\n";
	return 0;
}