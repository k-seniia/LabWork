#include "Circle.h"
#include "Ellipse.h"
#include "RegularPolygon.h"

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(nullptr));

	bool flag = true;
	while (flag) {
		int choise{};
		cout << "Оберiть завдання iз запропонованого меню:" << endl;
		cout << "1 - Тестування класу Ellipse" << endl;
		cout << "2 - Тестування класу Circle" << endl;
		cout << "3 - Тестування класу Polygon" << endl;
		cout << "4 - Тестування класу RegularPolygon" << endl;
		cout << "0 - Вихiд iз програми" << endl;
		cout << "Ваш вибiр -> "; cin >> choise; cout << endl;

		switch (choise) {
		case 0: flag = false; break;
		case 1: testEllipse(); break;
		case 2:	testCircle(); break;
		case 3: testPolygon(); break;
		case 4:	testRegularPolygon(); break;
		default: cout << "Невiрний вибiр, натиснiть ENTER та оберiть знову" << endl; break;
		}

		cout << endl << endl;
		system("pause");
		system("cls");
	}

	return EXIT_SUCCESS;
}