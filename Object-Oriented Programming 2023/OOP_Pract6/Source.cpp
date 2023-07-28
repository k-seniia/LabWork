#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

#define DEBUG

bool In_30_70(int x) {
	return x > 30 && x < 70;
}

int main() {
	setlocale(LC_ALL, "ru");

	int N;
	cout << "  Введiть розмiр масиву -> "; cin >> N;

	vector<int> v(N);
#ifdef DEBUG
	// 1. Iнiцiалiзацiя масиву з випадковими значеннями
	cout << "\n1. Iнiцiалiзацiя масиву з випадковими значеннями" << endl;
	int range;
	cout << "  Введiть дiапазон [-N, N] для випадкових значень -> "; cin >> range;

	// Iнiцiалiзацiя генератора та розподiлу
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<int> distribution(-range, range);
	generate(v.begin(), v.end(), [&] {return distribution(generator); });

	/*vector<double> v5(N);
	srand(time(NULL));
	int rangemin, rangemax;
	cout << "min -> "; cin >> rangemin;
	cout << "max -> "; cin >> rangemax;
	for (int i = 0; i < N; i++) {
		v5[i] = (double)rand() / RAND_MAX * (rangemax - rangemin) + rangemin;
	}

	copy(v5.begin(), v5.end(), ostream_iterator<double>(cout, " "));
	cout << endl;*/

#else
	// 1. Iнiцiалiзацiя масиву з клавiатури
	cout << "\n1. Iнiцiалiзацiя масиву з клавiатури" << endl;
	cout << "  Введiть елементи масиву -> ";
	for (auto& a : v) {
		cin >> a;
	}
#endif // DEBUG

	// Виведення початкового масиву
	cout << "    Початковий масив: ";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << "    Розмiр масиву: " << v.size() << endl;

	// 3. Знаходження мiнiмального та максимального значення ВСЬОГО МАСИВУ
	cout << "\n3. Знаходження мiнiмального та максимального значення ВСЬОГО МАСИВУ" << endl;
	int min = *min_element(v.begin(), v.end());
	int max = *max_element(v.begin(), v.end());

	cout << "\tМiнiмальне значення ВСЬОГО МАСИВУ: " << min << endl;
	cout << "\tМаксимальне значення ВСЬОГО МАСИВУ: " << max << endl;

	// 3. Знаходження мiнiмального та максимального значення ЗАДАНОГО ДIАПАЗОНУ
	cout << "\n3. Знаходження мiнiмального та максимального значення ЗАДАНОГО ДIАПАЗОНУ" << endl;
	int rangeStart, rangeEnd;
	cout << "  Введiть початок дiапазону вiд 0 до " << v.size() - 1 << " -> "; cin >> rangeStart;
	cout << "  Введiть кiнець дiапазону вiд " << rangeStart + 1 << " до " << v.size() - 1 << " -> "; cin >> rangeEnd;

	min = *min_element(v.begin() + rangeStart, v.begin() + rangeEnd + 1);
	max = *max_element(v.begin() + rangeStart, v.begin() + rangeEnd + 1);

	cout << "    Заданий дiапазон: ";
	copy(v.begin() + rangeStart, v.begin() + rangeEnd + 1, ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "\tМiнiмальне значення ЗАДАНОГО ДIАПАЗОНУ: " << min << endl;
	cout << "\tМаксимальне значення ЗАДАНОГО ДIАПАЗОНУ: " << max << endl;

	// 4. Сортування масиву за збiльшенням
	cout << "\n4. Сортування масиву за збiльшенням" << endl;
	sort(v.begin(), v.end());

	cout << "    Масив пiсля сортування за збiльшенням: ";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	// 5. Вставка елементiв З ЗАДАНОЇ ПОЗИЦIЇ у масив
	cout << "\n5. Вставка елементiв З ЗАДАНОЇ ПОЗИЦIЇ у масив" << endl;
	int position, numElements;
	cout << "  Введiть позицiю для вставки елементiв вiд 0 до " << v.size() - 1 << " -> "; cin >> position;
	cout << "  Введiть кiлькiсть елементiв для вставки -> "; cin >> numElements;

	vector<int> elements(numElements);
	cout << "  Введiть значення елементiв -> ";
	for (int i = 0; i < numElements; i++) {
		cin >> elements[i];
	}

	v.insert(v.begin() + position, elements.begin(), elements.end());

	cout << "    Масив пiсля вставки елементiв: ";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << "    Розмiр масиву: " << v.size() << endl;

	// 6. Видалення елементiв З ЗАДАНОЇ ПОЗИЦIЇ у масивi
	cout << "\n6. Видалення елементiв З ЗАДАНОЇ ПОЗИЦIЇ у масивi" << endl;
	cout << "  Введiть позицiю для видалення елементiв вiд 0 до " << v.size() - 1 << " -> "; cin >> position;
	cout << "  Введiть кiлькiсть елементiв для видалення до " << v.size() - position << " -> "; cin >> numElements;

	v.erase(v.begin() + position, v.begin() + position + numElements);

	cout << "    Масив пiсля видалення елементiв: ";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << "    Розмiр масиву: " << v.size() << endl;

	// 7. Сортування ЗАДАНОГО ДIАПАЗОНУ масиву за зменшенням
	cout << "\n7. Сортування ЗАДАНОГО ДIАПАЗОНУ масиву за зменшенням" << endl;
	cout << "  Введiть початок дiапазону вiд 0 до " << v.size() - 1 << " -> "; cin >> rangeStart;
	cout << "  Введiть кiнець дiапазону вiд " << rangeStart + 1 << " до " << v.size() - 1 << "-> "; cin >> rangeEnd;

	stable_sort(v.begin() + rangeStart, v.begin() + rangeEnd + 1, greater<int>());

	cout << "    Масив пiсля сортування заданого дiапазону за зменшенням: ";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "Iндивiдуальне завдання" << endl;

	// Створення та iнiцiалiзацiя векторiв v1 та v2
	vector<int> v1;
	vector<int> v2(10, 0);

	vector<int> values = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	v1.insert(v1.end(), values.begin(), values.end());

	cout << "  Виведення початкових векторiв:" << endl;
	cout << "    Вектор v1: ";
	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "    Вектор v2: ";
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	replace_copy_if(v1.begin(), v1.end(), v2.begin(), In_30_70, 5);

	cout << "Виведення результуючих векторiв:" << endl;
	cout << "    Вектор v1: ";
	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "    Вектор v2: ";
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
