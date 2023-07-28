#include "Student.h"

int main() {
#pragma region Ukranian
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Ukrainian");
#pragma endregion
	srand(time(NULL));

	int n = rand() % 10 + 10;
	Student* students = new Student[n];
	for (int i = 0; i < n; i++)
		students[i].readbin();

	bool flag = true;
	while (flag) {
		int choise{};
		cout << "Оберіть завдання із запропонованого меню:" << endl;
		cout << "1 - перелік студентів заданого факультету" << endl;
		cout << "2 - перелік студентів для каждого факультета и курса" << endl;
		cout << "3 - список студентів, родившихся после заданного года" << endl;
		cout << "0 - Вихід із програми" << endl;
		cout << "Ваш вибір -> "; cin >> choise; cout << endl;

		switch (choise) {
		case 0: flag = false; break;
		case 1:
			task1(students,n);
			break;
		case 2:
			task2(students,n);
			break;
		case 3:
			task3(students,n);
			break;
		default: cout << "Невірний вибір, натисніть ENTER та оберіть знову" << endl; break;
		}
		cout << endl << endl;
		system("pause");
		system("cls");
	}
	return EXIT_SUCCESS;
}