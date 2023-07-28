#include <iostream>
#include <cmath>
#include <iomanip>
//ОБРОБКА БАГАТОВИМiРНИХ МАСИВiВ. ВИКОРИСТАННЯ ФУНКЦiЙ
using namespace std;

int M, N;

void task1(); void task2(); void task3(); void task4(); void task5();
void task6(); void task7(); void task8(); void task9(); void task10();

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	for (;;) {
		int choise{};
		cout << "Оберiть завдання - вiд 1 до 10" << endl;
		cout << "0 - Вихiд iз програми" << endl << endl;
		cout << "Ваш вибiр -> "; cin >> choise; cout << endl;
		
		if (choise >= 1 && choise <= 6) {
			cout << "Ведiть розмiр массиву:" << endl;
			N = rand() % 7 + 3;
			cout << "Квадратна матриця N -> "; /*cin >> N; M = N;*/ cout << N << endl;
		}
		else if (choise >= 7 && choise <= 10) {
			cout << "Ведiть розмiр массиву:" << endl;
			M = rand() % 7 + 3; 	N = rand() % 7 + 3;
			cout << "Довiльна матриця M -> "; /*cin >> M;*/ cout << M << endl;
			cout << setw(22) << "N -> "; /*cin >> N;*/ cout << N << endl;
		}

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

int** newmas(int r, int c, int d) {
	int** mas = new int* [r];
	for (int i = 0; i < r; i++) {
		mas[i] = new int[c];
		for (int j = 0; j < c; j++) {
			//cout << "Введiть [" << i << "][" << j << "] елемент масиву -> ";
			//cin >> mas[i][j];
			mas[i][j] = rand() % d;
		}
	}
	return mas;
}

void maxij(int** mas, int& max, int& maxi, int& maxj) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (mas[i][j] > max) {
				max = mas[i][j];
				maxi = i;
				maxj = j;
			}
}

void minij(int** mas, int& min, int& mini, int& minj) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (mas[i][j] < min) {
				min = mas[i][j];
				mini = i;
				minj = j;
			}
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print(int** mas, int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cout << setw(4) << mas[i][j];
		cout << endl;
	}
}

void task1() {
	cout << "\n\n----- Завдання 1 -----"
		<< "\nЗнайти максимальний (мiнiмальний) елемент масиву"
		<< "\nта виконати сортування головної дiагоналi"
		<< "\nза зменшенням(збiльшенням) значень її елементiв.\n\n";

	int** mas = newmas(N, N, 100);
	int max = INT_MIN, min = INT_MAX, maxi{}, maxj{}, mini{}, minj{};
	cout << "Початковий масив:\n";
	print(mas, N, N);
	maxij(mas, max, maxi, maxj);
	minij(mas, min, mini, minj);
	cout << "\nmax = " << max << "\ti = " << maxi << "\tj = " << maxj << endl;
	cout << "\nmin = " << min << (min < 10 ? "\t\ti = " : "\ti = ") << mini << "\tj = " << minj << endl;
	cout << "\nCортування головної дiагоналi за збiльшенням:\n";
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - i - 1; j++)
			if (mas[j][j] > mas[j + 1][j + 1])
				swap(&mas[j][j], &mas[j + 1][j + 1]);
	print(mas, N, N);
	cout << "\nCортування головної дiагоналi за зменшенням:\n";
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - i - 1; j++)
			if (mas[j][j] < mas[j + 1][j + 1])
				swap(&mas[j][j], &mas[j + 1][j + 1]);
	print(mas, N, N);
	delete[] mas;
}

void task2() {
	cout << "\n\n----- Завдання 2 -----"
		<< "\nВизначити чи є матриця магiчним квадратом\n\n";

	int** mas = newmas(N, N, 100);
	int* sum = new int[N * 2]{}; int mk{};
	cout << "Початковий масив:\n";
	print(mas, N, N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			sum[i] += mas[i][j];
			sum[N + i] += mas[j][i];
		}
	cout << "\nCуми елементiв у всiх рядках та стовбцях: " << endl;
	for (int i = 0; i < N * 2; i++)
		cout << setw(5) << sum[i];
	cout << endl;
	for (int i = 0; i < N * 2 - 1; i++)
		if (sum[i] == sum[i + 1])
			mk++;
	if (mk == N * 2)
		cout << "\nМатриця є магiчним квадратом" << endl;
	else
		cout << "\nМатриця не є магiчним квадратом" << endl;
	delete[] mas;
}

void task3() {
	cout << "\n\n----- Завдання 3 -----"
		<< "\nЗнайти рядки з максимальним i мiнiмальним елементом"
		<< "\nта змiнити їх мiсцями.\n\n";

	int** mas = newmas(N, N, 100);
	int max = INT_MIN, min = INT_MAX, maxi{}, maxj{}, mini{}, minj{};
	cout << "Початковий масив:\n";
	print(mas, N, N);
	maxij(mas, max, maxi, maxj);
	minij(mas, min, mini, minj);
	cout << "\nmax = " << max << "\tmin = " << min << endl;
	cout << "\ni max = " << maxi << "\ti min = " << mini << endl;
	for (int j = 0; j < N; j++)
		swap(&mas[mini][j], &mas[maxi][j]);
	cout << "\nЗмiнений масив:\n";
	print(mas, N, N);
	delete[] mas;
}

void task4() {
	cout << "\n\n----- Завдання 4 -----"
		<< "\nЗнайти стовпчики з мiнiмальним i максимальним елементом."
		<< "\nВиконати сортування цих стовпчикiв "
		<< "\nза збiльшенням значень їх елементiв.\n\n";

	int** mas = newmas(N, N, 100);
	int max = INT_MIN, min = INT_MAX, maxi{}, maxj{}, mini{}, minj{};
	cout << "Початковий масив:\n";
	print(mas, N, N);
	maxij(mas, max, maxi, maxj);
	minij(mas, min, mini, minj);
	cout << "\nmax = " << max << "\tmin = " << min << endl;
	cout << "\nj max = " << maxj << "\tj min = " << minj << endl;
	cout << "\nCортування обраних стовпцiв за збiльшенням:\n";
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - i - 1; j++) {
			if (mas[j][maxj] > mas[j + 1][maxj])
				swap(&mas[j][maxj], &mas[j + 1][maxj]);
			if (mas[j][minj] > mas[j + 1][minj])
				swap(&mas[j][minj], &mas[j + 1][minj]);
		}
	print(mas, N, N);
	delete[] mas;
}

void task5() {
	cout << "\n\n----- Завдання 5 -----"
		<< "\nЗнайти стовпчики з мiнiмальним i максимальним елементом масиву"
		<< "\nта замiнити їх мiсцями.\n\n";

	int** mas = newmas(N, N, 100); 
	int max = INT_MIN, min = INT_MAX, maxi{}, maxj{}, mini{}, minj{};
	cout << "Початковий масив:\n";
	print(mas, N, N);
	maxij(mas, max, maxi, maxj);
	minij(mas, min, mini, minj);
	cout << "\nmax = " << max << "\tmin = " << min << endl;
	cout << "\nj max = " << maxj << "\tj min = " << minj << endl;
	for (int i = 0; i < N; i++)
		swap(&mas[i][minj], &mas[i][maxj]);
	cout << "\nЗмiнений масив:\n";
	print(mas, N, N);
	delete[] mas;
}

void task6() {
	cout << "\n\n----- Завдання 6 -----"
		<< "\nПомiняти мiсцями елементи вiдносно"
		<< "\nдо головної/побiчної дiагоналi\n\n";

	int** mas = newmas(N, N, 100);
	cout << "Початковий масив:\n";
	print(mas, N, N);
	cout << "\nЗмiнений масив вiдповiдно до головної дiагоналi\n";
	for (int i = 0; i < N; i++)
		for (int j = i; j < N; j++)
			if (i != j)
				swap(&mas[i][j], &mas[j][i]);
	print(mas, N, N);
	cout << "\nЗмiнений масив вiдповiдно до побiчної дiагоналi\n";
	for (int i = 0; i < N; i++)
		for (int j = N - i - 1; j < N; j++)
			if (i + j != N - 1)
				swap(&mas[i][j], &mas[N - j - 1][N - i - 1]);
	print(mas, N, N);
	delete[] mas;
}

void task7() {
	cout << "\n\n----- Завдання 7 -----"
		<< "\nВизначити координати всiх сiдлових точок матрицi.\n\n";

	int maxi{}, maxj{}, mini{}, minj{}, st = M;
	int** mas = newmas(M, N, 50);
	cout << "Початковий масив:\n";
	print(mas, M, N);
	for (int i = 0; i < M; i++) {
		int max = INT_MIN, min = INT_MAX;
		for (int j = 0; j < N; j++)
			if (mas[i][j] > max) {
				max = mas[i][j];
				maxj = j;
			}
		for (int j = 0; j < M; j++)
			if (mas[j][maxj] < min) {
				min = mas[j][maxj];
				mini = j;
			}
		if (max == min)
			cout << "\nЕлемент матрицi [" << mini << "][" << maxj << "] = " << max << "є сiдловою точкою\n";
		else
			st--;
	}
	if (st == 0)
		cout << "\nМатриця не має сiдлових точок";
	delete[] mas;
}

void task8() {
	cout << "\n\n----- Завдання 8 -----"
		<< "\nПомiняти мiсцями елементи дзеркально вiдносно"
		<< "\nвертикальної осi симетрiї матрицi\n\n";

	int** mas = newmas(M, N, 50);
	cout << "Початковий масив:\n";
	print(mas, M, N);
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N / 2; j++)
			swap(&mas[i][j], &mas[i][N - 1 - j]);
	cout << "\nЗмiнений масив:\n";
	print(mas, M, N);
	delete[] mas;
}

void task9() {
	cout << "\n\n----- Завдання 9 -----"
		<< "\nУпорядкувати рядки матрицi так, щоб їх першi елементи"
		<< "\nутворювали зростаючу послiдовнiсть.\n\n";

	int** mas = newmas(M, N, 50);
	cout << "Початковий масив:\n";
	print(mas, M, N);
	for (int c = 0; c < M; c++)
		for (int i = 0; i < M - 1; i++)
			if (mas[i][0] > mas[i + 1][0])
				for (int j = 0; j < N; j++)
					swap(&mas[i][j], &mas[i + 1][j]);
	cout << "\nЗмiнений масив:\n";
	print(mas, M, N);
	delete[] mas;
}

void task10() {
	cout << "\n\n----- Завдання 10 -----"
		<< "\nВiдсортувати матрицю за зменшенням її елементiв.\n\n";

	int** mas = newmas(M, N, 50);
	cout << "Початковий масив:\n";
	print(mas, M, N);
	for (int c = 0; c <= (M * N); c++) {
		int x{}, y{};
		for (int i = 0; i < M; i++)
			for (int j = (i ? 0 : 1); j < N; j++) {
				if (mas[x][y] < mas[i][j])
					swap(&mas[x][y], &mas[i][j]);
				x = i; y = j;
			}
	}
	cout << "\nЗмiнений масив:\n";
	print(mas, M, N);
	delete[] mas;
}