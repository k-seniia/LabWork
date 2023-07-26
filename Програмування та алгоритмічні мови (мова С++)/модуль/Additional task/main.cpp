#include "Header.h"

int main() {
#pragma region Ukranian
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Ukrainian");
#pragma endregion
	srand(time(NULL));

	vector<string> log;

	if (read_from_file(log)) {

		cout << " Âõ³äí³ äàí³:" << endl;
		for (int i = 0; i < log.size(); i++)
			cout << "\t" << log[i] << endl;

		dupli(log);

		cout << " \nÂèõ³äí³ äàí³:" << endl;
		for (int i = 0; i < log.size(); i++)
			cout << "\t" << log[i] << endl;

		write_to_file(log);
	}

	return EXIT_SUCCESS;
}