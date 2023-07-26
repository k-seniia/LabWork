#pragma region Includes
#include <locale>
#include "windows.h"
#include "Header.h"
#pragma endregion

int main() {
#pragma region Ukranian
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Ukrainian");
#pragma endregion
	srand(time(NULL));

	bool flag = true;
	while (flag) {
		int choise{};
		cout << "������ �������� �� ��������������� ����:" << endl;
		cout << "1 - �������� 1" << endl;
		cout << "2 - �������� 2" << endl;
		cout << "0 - ����� �� ��������" << endl;
		cout << "��� ���� -> "; cin >> choise; cout << endl;

		switch (choise) {
		case 0: flag = false; break;
		case 1: task1(); break;
		case 2: task2(); break;
		default: cout << "������� ����, �������� ENTER �� ������ �����" << endl; break;
		}
		cout << endl << endl;
		system("pause");
		system("cls");
	}

	return EXIT_SUCCESS;
}

void task1() {
	string buf;

	if (read_from_file_task1(buf)) {
		cout << buf << endl;;

		int count{}, num[26]{}, n{};
		char let[26]{};

		do_task1(buf, count, let, num, n);
		sort(let, num, n);

		cout << "\nthe number of words that have an odd length -> " << count << endl;
		cout << "\nfrequency of letters:\t";
		for (int i = 0; i < n; i++) {
			if (i % 5 == 0 && i != 0)
				cout << endl << "\t\t\t";
			cout << let[i] << " - " << num[i] << "  ";
		}

		write_to_file_task1(count, let, num, n);
	}
}

void task2() {
	string buf;

	if (read_from_file_task2(buf)) {
		cout << buf << endl;

		string time = do_task2(buf);

		cout << time << endl;;
		write_to_file_task2(time);
	}
}