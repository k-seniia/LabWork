#include "Header.h"

int main() {
#pragma region Ukranian
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Ukrainian");
#pragma endregion
	srand(time(NULL));

	vector<tourist> t;

	if (read_from_file(t)) {

		for (auto& a : t)
			cout << " " << a.name << "  \t" << a.age << " р., " << a.gender << endl;
		cout << endl;

		int m_age = middle_age(t);
		cout << "Середній вік всіх туристів - " << m_age << endl << endl;

		vector<string> w_name;
		woman_name(t, w_name);
		cout << "Прізвища всіх жінок: ";
		for (auto& a : w_name)
			cout << a << " ";
		cout << endl;

		write_to_file(m_age, w_name);
	}

	return EXIT_SUCCESS;
}