#include "Circle.h"
#include "Ellipse.h"
#include "RegularPolygon.h"

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(nullptr));

	bool flag = true;
	while (flag) {
		int choise{};
		cout << "����i�� �������� i� ��������������� ����:" << endl;
		cout << "1 - ���������� ����� Ellipse" << endl;
		cout << "2 - ���������� ����� Circle" << endl;
		cout << "3 - ���������� ����� Polygon" << endl;
		cout << "4 - ���������� ����� RegularPolygon" << endl;
		cout << "0 - ���i� i� ��������" << endl;
		cout << "��� ���i� -> "; cin >> choise; cout << endl;

		switch (choise) {
		case 0: flag = false; break;
		case 1: testEllipse(); break;
		case 2:	testCircle(); break;
		case 3: testPolygon(); break;
		case 4:	testRegularPolygon(); break;
		default: cout << "���i���� ���i�, ������i�� ENTER �� ����i�� �����" << endl; break;
		}

		cout << endl << endl;
		system("pause");
		system("cls");
	}

	return EXIT_SUCCESS;
}