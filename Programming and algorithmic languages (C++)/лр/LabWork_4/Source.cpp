#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#define N 50
#define DEBUG

// function prototypes
bool read_from_file(char*);
void write_to_file(int);
int find_groups1(char*);
int find_groups2(char*);
void debug_file();

int main() {
	srand(time(NULL));

	char buf[N];
	if (read_from_file(buf)) {
		for (int i = 0; i < N; i++)
			cout << buf[i];

		int n = find_groups1(buf);
		cout << "\n\nthe number of groups with five characters (1st method) -> " << n << endl;

		n = find_groups2(buf);
		cout << "\nthe number of groups with five characters (2nd method) -> " << n << endl;
		write_to_file(n);
	}
	return 0;
}

bool read_from_file(char* buf) {

#ifdef DEBUG
	debug_file();
	ifstream fin("debug_string.txt");
#else
	ifstream fin("string.txt");
#endif

	if (fin)
		fin.getline(buf, N, '\0');
	else {
		cout << "File not found." << endl;
		fin.close();
		return 0;
	}
	fin.close();
	return 1;
}

void write_to_file(int n) {
	ofstream fout("num of groups.txt");
	fout << "the number of groups with five characters -> " << n;
	fout.close();
}

int find_groups1(char* buf) {
	int count{}, ch{};
	for (int i = 0; i < N - 1; i++) {
		if (isspace(buf[i]))				// Повертає значення true, якщо buf[i] є пробілом, і false в інших випадках
			ch = 0;							// обнуляє кількість символів
		else if (isdigit(buf[i]))			// Повертає значення true, якщо buf[i] є цифрою, і false в інших випадках
			ch++;							// підраховує кількість символів
		if (ch == 5)
			count++;						// підраховує кількість груп з п'яти символів
		else if (ch == 6)
			count--;						// зменшує кількість груп, якщо група більше п'яти символів
	}
	return count;
}

#pragma warning(disable : 4996)
int find_groups2(char* buf) {
	const char* spt = " ";			// роздільник лексем
	int count{};
	char* tk = strtok(buf, spt);	// РОЗБІР РЯДКА НА ЛЕКСЕМИ. Повертає вказівник на наступну лексему (слово) в рядку
	//								// При першому виклику функції strtok перший параметр повинен вказувати на рядок, який розбирається на лексеми
	while (tk != NULL) {			// У разі якщо лексеми закінчилися, то функція повертає NULL
		if (strlen(tk) == 5)
			count++;				// підраховує кількість груп з п'яти символів
		tk = strtok(NULL, spt);		// При наступних викликах цей параметр повинен бути встановлений в NULL
	}								// бо після знаходження лексеми функція strtok записує після цієї лексеми на місце роздільника нульовий байт
	return count;
}

void debug_file() {
	ofstream fout("debug_string.txt");
	int l = rand() % 7 + 1, lc{};
	for (int i = 0; i < N; i++) {
		if (lc == l) {
			fout << ' ';
			lc = 0;
			l = rand() % 9 + 1;
		}
		else {
			fout << rand() % 2;
			lc++;
		}
	}
	fout << '\0';
	fout.close();
}