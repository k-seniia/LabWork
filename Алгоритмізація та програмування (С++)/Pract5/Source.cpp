#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdio>
#include "windows.h"
//РОБОТА З ФАЙЛАМИ
using namespace std;

#pragma warning(disable : 4996)

void task1(); void task2(); void task3(); void task4(); void task5();
void task6(); void task7(); void task8(); void task9(); void task10();

int main() {
#pragma region Ukranian
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Ukrainian");
#pragma endregion
	srand(time(NULL));

	for (;;) {
		int choise{};
		cout << "Оберiть завдання - вiд 1 до 10" << endl;
		cout << "0 - Вихiд iз програми" << endl << endl;
		cout << "Ваш вибiр -> "; cin >> choise; cout << endl;

		switch (choise) {
		case 0: return 0; break;
		case 1: task1(); break;
		case 2: task2(); break;
		case 3: task3(); break;
		case 4: task4(); break;
		case 5: task5(); break;
		case 6: task6(); break;
		case 7: task7(); break;
		case 8: task8(); break;
		case 9: task9(); break;
		case 10: task10(); break;
		default: cout << "Невiрний вибiр, натиснiть ENTER та оберiть знову" << endl; break;
		}
		cout << endl << endl;
		system("pause");
		system("cls");
	}

	cout << "\n\n\n\n\n";
	return 0;
}

void task1() {
	ofstream fout("strings.txt");
	fout << "is the first line\nis the second line\nis the third line";
	fout.close();

	const int s = 50;
	string mas[3];
	char buf[s];
	
	ifstream fin("strings.txt");
	for (int i = 0; i < 3; i++) {
		fin.getline(buf, s);
		mas[i] = buf;
		cout << mas[i] << endl;
	}
	fin.close();
}

void task2() {
	ofstream fout("inputFile.txt");
	for (int i = 0; i < 10; i++)
		fout << rand() % 10 << " ";
	fout.close();

	int buf{};
	int mas[10]{};

	ifstream fin("inputFile.txt");
	fout.open("outputFile.txt");
	cout << "Випадкові цілі числа -> inputFile.txt\n\t";
	for (int i = 0; i < 10; i++) {
		fin >> mas[i];
		cout << setw(3) << mas[i];
		fout << mas[i] * 2 << endl;
	}
	fin.close();
	fout.close();
	
	fin.open("outputFile.txt");
	cout << "\n\nВипадкові цілі числа помножені на 2 -> outputFile.txt\n\t";
	for (int i = 0; i < 10; i++) {
		fin >> mas[i];
		cout << setw(3) << mas[i];
	}
	fin.close();
}

void task3() {
	cout << "Для завершення введення речення поставте крапку та натисніть Enter" << endl << endl;
	char buf[128];
	cin.getline(buf, 127, '.');

	cout << "Кількість символів у рядку = " << strlen(buf) << endl;
		
	int word{}, i{}, count{};
	while (buf[i] != '\0') {
		if (buf[i] != ' ' && word == 0) {
			word = 1;
			count++;
		}
		else if (buf[i] == ' ')
			word = 0;
		i++;
	}
	cout << "Кількість слів у рядку = " << count;
}

void task4() {
	ofstream fout("4.txt");
	fout << "Carroll " << "Hill " << "Neal " << "White " << "Snyder";
	fout.close();

	string buf[5];
	ifstream fin("4.txt");
	for (int i = 0; i < 5; i++) {
		fin >> buf[i];
		cout << buf[i] << " ";
	}
	fin.close();
}

void task5() {
	ofstream fout("input.txt");
	fout << "15 20" << endl;
	fout << "10" << endl;
	fout << "2 3 4 5 6 7 8 19 900001 123" << endl;
	fout << "Obozrevatel.com" << endl;
	fout.close();

	char buf[30];
	ifstream fin("input.txt");
	for (int i = 0; i < 4; i++) {
		fin.getline(buf, 30);
		cout << buf << endl;;
	}
	fin.close();
}

void task6() {
	ofstream fout("6.txt");
	for (int i = 0; i < 10; i++)
		fout << rand() % 51 << " ";
	fout.close();

	string s; int sum{}, count{};

	ifstream fin("6.txt");
	for (int i = 0; i < 10; i++) {
		fin >> s;
		count++;
		sum += size(s);
	}
	cout << "Кількість чисел = " << count << endl;
	cout << "Kількість символів, які використані для запису чисел(окрім пробілів) = " << sum;
	fin.close();
}

void task7() {
	ofstream fout("abc.txt");
	for (int i = 0; i < rand() % 100; i++)
		fout << rand() % 1000 / 100.0 << " ";
	fout.close();

	/*double mas[100]; */ int i = -1;
	string buf[100]; int count{};
	ifstream fin("abc.txt");
	while(!fin.eof()) {
		i++;
		fin >> buf[i];
		cout << buf[i] << " ";
		count += size(buf[i]);
	}
	cout << endl << count << endl;
	fin.close();

	for (int j = 0; j < i; j++)
		for (int k = 0; k < i - j; k++)
			if (buf[k] > buf[k + 1])
				swap(buf[k], buf[k + 1]);
		
	fout.open("abc.txt", ios::app);
	fout << "\t";
	for (int j = 0; j <= i; j++)
		fout << buf[j] << " ";
	fout.close();

	string buf1;
	fin.open("abc.txt");
	while (!fin.eof()) {
		fin >> buf1;
		cout << buf1 << " ";
	}
	fin.close();

}

void task8() {
	ofstream fout("8.txt");
	cout << "Для завершення введення речення поставте крапку та натисніть Enter" << endl << endl;
	char buf[256];
	for (int i = 0; i < 3; i++) {
		cin.getline(buf, 256, '.');
		fout << buf;
	}
	fout.close();

	ifstream fin("8.txt");
	while (fin.getline(buf, 256))
		cout << buf << endl;
	fin.close();
}

void task9() {
	ofstream fout("9.txt");
	fout << "один символ пробілу";
	fout.close();

	/*fstream file("9.txt");
	file.seekg(0, ios::end);
	int s = file.tellg();
	file.close();*/

	string buf;
	ifstream fin("9.txt");
	fin >> buf;
	fin.close();

	fout.open("9.txt");
	fout << buf;
	fout.close();
}

void task10() {
	int k = rand() % 55 + 1;
	cout << "Обмежена кількість символів -> " << k << endl;
	
	ofstream fout("10.txt");
	cout << "Для завершення введення речення поставте крапку та натисніть Enter" << endl << endl;
	char buf[256];
	for (int i = 0; i < 3; i++) {
		cin.getline(buf, 256, '.');
		fout << buf;
	}
	fout.close();

	ofstream fout1("first.txt"), fout2("second.txt");
	ifstream fin("10.txt");
	while(fin.getline(buf,256)){
		if (strlen(buf) >= k) {
			for (int i = 0; i < k; i++)
				fout1 << buf[i];
			fout1 << endl;
			fout2 << buf[k];
		}
		else {
			fout1 << buf << endl;
			fout2 << " ";
		}
	}
	fin.close();
	fout1.close(); fout2.close();
}