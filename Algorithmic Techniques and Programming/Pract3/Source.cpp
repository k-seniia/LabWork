#include <iostream>
#include <cmath>
#include <iomanip>
//ОБРОБКА БАГАТОВИМiРНИХ МАСИВiВ.
using namespace std;

const int n = 7, m = 6;
int M, N;

void task1(); void task2(); void task3(); void task4(); void task5();
void task6(); void task7(); void task8(); void task9(); void task10();

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	
	for (;;) {
		int choise{};
		cout << "Оберiть завдання - вiд 1 до 10" << endl;
		cout << "0 - Вихiд iз програми" << endl;
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

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void printn(int mas[][n]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << setw(4) << mas[i][j];
		cout << endl;
	}
}
void printm(int mas[][m]) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++)
			cout << setw(4) << mas[i][j];
			cout << endl;
	}
}
void print(int** mas, int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << setw(4) << mas[i][j];
		}
		cout << endl;
	}
}

void task1() {
	cout << "\n\n----- Завдання 1 -----"
		<< "\nЗнайти максимальний (мiнiмальний) елемент масиву"
		<< "\nта виконати сортування головної дiагоналi"
		<< "\nза зменшенням(збiльшенням) значень її елементiв.\n\n";

	int mas1[n][n]{}, max1 = INT_MIN, min1 = INT_MAX;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			//cout << "Введiть [" << i << "][" << j << "] елемент масиву -> ";
			//cin >> mas1[i][j];
			mas1[i][j] = rand() % 100;
		}
	cout << "Початковий масив:\n";
	printn(mas1);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (mas1[i][j] > max1)
				max1 = mas1[i][j];
			if (mas1[i][j] < min1)
				min1 = mas1[i][j];
		}
	cout << "\nmax = " << max1 << "\tmin = " << min1 << endl;
	cout << "\nCортування головної дiагоналi за збiльшенням:\n";
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (mas1[j][j] > mas1[j + 1][j + 1])
				swap(&mas1[j][j], &mas1[j + 1][j + 1]);
	printn(mas1);
	cout << "\nCортування головної дiагоналi за зменшенням:\n";
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (mas1[j][j] < mas1[j + 1][j + 1])
				swap(&mas1[j][j], &mas1[j + 1][j + 1]);
	printn(mas1);
}

void task2() {
	cout << "\n\n----- Завдання 2 -----"
		<< "\nВизначити чи є матриця магiчним квадратом\n\n";

	int mas2[m][m]{}, sum[m * 2]{}, mk{};
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++) {
			//cout << "Введiть [" << i << "][" << j << "] елемент масиву -> ";
			//cin >> mas2[i][j];
			mas2[i][j] = rand() % 10;
		}
	cout << "Початковий масив:\n";
	printm(mas2);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++) {
			sum[i] += mas2[i][j];
			sum[m + i] += mas2[j][i];
		}
	cout << "\nCуми елементiв у всiх рядках та стовбцях: ";
	for (int i = 0; i < m * 2; i++)
		cout << setw(5) << sum[i];
	cout << endl;
	for (int i = 0; i < m * 2 - 1; i++)
		if (sum[i] == sum[i + 1])
			mk++;
	if (mk == m * 2)
		cout << "\nМатриця є магiчним квадратом" << endl;
	else
		cout << "\nМатриця не є магiчним квадратом" << endl;
}

void task3() {
	cout << "\n\n----- Завдання 3 -----"
		<< "\nЗнайти рядки з максимальним i мiнiмальним елементом"
		<< "\nта змiнити їх мiсцями.\n\n";

	int mas3[n][n]{}, max3 = INT_MIN, max3_i{}, min3 = INT_MAX, min3_i{};
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			//cout << "Введiть [" << i << "][" << j << "] елемент масиву -> ";
			//cin >> mas3[i][j];
			mas3[i][j] = rand() % 100;
		}
	cout << "Початковий масив:\n";
	printn(mas3);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (mas3[i][j] > max3) {
				max3 = mas3[i][j];
				max3_i = i;
			}
			if (mas3[i][j] < min3) {
				min3 = mas3[i][j];
				min3_i = i;
			}
		}
	cout << "\nmax = " << max3 << "\tmin = " << min3 << endl;
	cout << "\ni max = " << max3_i << "\ti min = " << min3_i << endl;
	for (int j = 0; j < n; j++)
		swap(&mas3[min3_i][j], &mas3[max3_i][j]);
	cout << "\nЗмiнений масив:\n";
	printn(mas3);
}

void task4() {
	cout << "\n\n----- Завдання 4 -----"
		<< "\nЗнайти стовпчики з мiнiмальним i максимальним елементом."
		<< "\nВиконати сортування цих стовпчикiв "
		<< "\nза збiльшенням значень їх елементiв.\n\n";

	int mas4[m][m]{}, max4 = INT_MIN, max4_j{}, min4 = INT_MAX, min4_j{};
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++) {
			//cout << "Введiть [" << i << "][" << j << "] елемент масиву -> ";
			//cin >> mas4[i][j];
			mas4[i][j] = rand() % 100;
		}
	cout << "Початковий масив:\n";
	printm(mas4);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++) {
			if (mas4[i][j] > max4) {
				max4 = mas4[i][j];
				max4_j = j;
			}
			if (mas4[i][j] < min4) {
				min4 = mas4[i][j];
				min4_j = j;
			}
		}
	cout << "\nmax = " << max4 << "\tmin = " << min4 << endl;
	cout << "\nj max = " << max4_j << "\tj min = " << min4_j << endl;
	cout << "\nCортування обраних стовпцiв за збiльшенням:\n";
	for (int i = 0; i < m - 1; i++)
		for (int j = 0; j < m - i - 1; j++) {
			if (mas4[j][max4_j] > mas4[j + 1][max4_j])
				swap(&mas4[j][max4_j], &mas4[j + 1][max4_j]);
			if (mas4[j][min4_j] > mas4[j + 1][min4_j])
				swap(&mas4[j][min4_j], &mas4[j + 1][min4_j]);
		}
	printm(mas4);
}

void task5() {
	cout << "\n\n----- Завдання 5 -----"
		<< "\nЗнайти стовпчики з мiнiмальним i максимальним елементом масиву"
		<< "\nта замiнити їх мiсцями.\n\n";

	int mas5[n][n]{}, max5 = INT_MIN, max5_j{}, min5 = INT_MAX, min5_j{};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//cout << "Введiть [" << i << "][" << j << "] елемент масиву -> ";
			//cin >> mas5[i][j];
			mas5[i][j] = rand() % 100;
		}
	}
	cout << "Початковий масив:\n";
	printn(mas5);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mas5[i][j] > max5) {
				max5 = mas5[i][j];
				max5_j = j;
			}
			if (mas5[i][j] < min5) {
				min5 = mas5[i][j];
				min5_j = j;
			}
		}
	}
	cout << "\nmax = " << max5 << "\tmin = " << min5 << endl;
	cout << "\nj max = " << max5_j << "\tj min = " << min5_j << endl;
	for (int i = 0; i < n; i++)
		swap(&mas5[i][min5_j], &mas5[i][max5_j]);
	cout << "\nЗмiнений масив:\n";
	printn(mas5);
}

void task6() {
	cout << "\n\n----- Завдання 6 -----"
		<< "\nВизначити, чи є матриця симетричною вiдповiдно"
		<< "\nдо головної/побiчної дiагоналi\n\n";

	int mas6[n][n]{}, sm{};
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			//cout << "Введiть [" << i << "][" << j << "] елемент масиву -> ";
			//cin >> mas6[i][j];
			mas6[i][j] = rand() % 10;
		}
	cout << "Початковий масив:\n";
	printn(mas6);
	cout << "\nПеревiрка матрицi на симетричнiсть вiдповiдно до головної дiагоналi\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				cout << setw(3) << '-';
			if (i != j && mas6[i][j] == mas6[j][i]) {
				cout << setw(3) << mas6[i][j];
				sm++;
			}
			if (i != j && mas6[i][j] != mas6[j][i])
				cout << setw(3) << " ";
		}
		cout << endl;
	}
	if (sm == n * n - n)
		cout << "\nMатриця симетрична вiдповiдно до головної дiагоналi\n";
	else
		cout << "\nMатриця не симетрична вiдповiдно до головної дiагоналi\n";
	sm = 0;
	cout << "\nПеревiрка матрицi на симетричнiсть вiдповiдно до побiчної дiагоналi\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i + j == n - 1)
				cout << setw(3) << '-';
			if (i + j != n - 1 && mas6[i][j] == mas6[n - j - 1][n - i - 1]) {
				cout << setw(3) << mas6[i][j];
				sm++;
			}
			if (i + j != n - 1 && mas6[i][j] != mas6[n - j - 1][n - i - 1])
				cout << setw(3) << " ";
		}
		cout << endl;
	}
	if (sm == n * n - n)
		cout << "\nMатриця симетрична вiдповiдно до побiчної дiагоналi\n";
	else
		cout << "\nMатриця не симетрична вiдповiдно до побiчної дiагоналi\n";
}

void task7() {
	cout << "\n\n----- Завдання 7 -----"
		<< "\nВизначити координати всiх сiдлових точок матрицi.\n\n";

	int mas7[n][n]{}, max7_j{}, min7_i{}, st = n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//cout << "Введiть [" << i << "][" << j << "] елемент масиву -> ";
			//cin >> mas7[i][j];
			mas7[i][j] = rand() % 50;
		}
	}
	cout << "Початковий масив:\n";
	printn(mas7);
	for (int i = 0; i < n; i++) {
		int max7 = INT_MIN, min7 = INT_MAX;
		for (int j = 0; j < n; j++) {
			if (mas7[i][j] > max7) {
				max7 = mas7[i][j];
				max7_j = j;
			}
		}
		for (int a = 0; a < n; a++) {
			if (mas7[a][max7_j] < min7) {
				min7 = mas7[a][max7_j];
				min7_i = a;
			}
		}
		if (max7 == min7)
			cout << "\nЕлемент матрицi [" << min7_i << "][" << max7_j << "] = " << max7 << "є сiдловою точкою\n";
		else
			st--;
	}
	if (st == 0)
		cout << "\nМатриця не має сiдлових точок";
}

void task8() {
	cout << "\n\n----- Завдання 8 -----"
		<< "\nПомiняти мiсцями елементи дзеркально вiдносно"
		<< "\nвертикальної осi симетрiї матрицi\n\n";

	//cin >> M >> N;
	M = rand() % 8 + 2; 	N = rand() % 8 + 2;
	int** mas8 = new int* [M];
	for (int i = 0; i < M; i++) {
		mas8[i] = new int[N];
		for (int j = 0; j < N; j++) {
			//cout << "Введiть [" << i << "][" << j << "] елемент масиву -> ";
			//cin >> mas8[i][j];
			mas8[i][j] = rand() % 50;
		}
	}
	cout << "Початковий масив:\n";
	print(mas8, M, N);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N / 2; j++) {
			swap(&mas8[i][j], &mas8[i][N - 1 - j]);
		}
	}
	cout << "\nЗмiнений масив:\n";
	print(mas8, M, N);
	delete [] mas8;
}

void task9() {
	cout << "\n\n----- Завдання 9 -----"
		<< "\nУпорядкувати її рядки так, щоб їх першi елементи"
		<< "\nутворювали зростаючу послiдовнiсть.\n\n";

	//cin >> M >> N;
	M = rand() % 8 + 2; 	N = rand() % 8 + 2;
	int** mas9 = new int* [M];
	for (int i = 0; i < M; i++) {
		mas9[i] = new int[N];
		for (int j = 0; j < N; j++) {
			//cout << "Введiть [" << i << "][" << j << "] елемент масиву -> ";
			//cin >> mas9[i][j];
			mas9[i][j] = rand() % 50;
		}
	}
	cout << "Початковий масив:\n";
	print(mas9, M, N);
	for (int c = 0; c < M; c++) {
		for (int i = 0; i < M - 1; i++) {
			if (mas9[i][0] > mas9[i + 1][0]) {
				for (int j = 0; j < N; j++) {
					swap(&mas9[i][j], &mas9[i + 1][j]);
				}
			}
		}
	}
	cout << "\nЗмiнений масив:\n";
	print(mas9, M, N);
	delete [] mas9;
}

void task10() {
	cout << "\n\n----- Завдання 10 -----"
		<< "\nВiдсортувати матрицю за зменшенням її елементiв.\n\n";

	//cin >> M >> N;
	M = rand() % 8 + 2; 	N = rand() % 8 + 2;
	int** mas10 = new int* [M];
	for (int i = 0; i < M; i++) {
		mas10[i] = new int[N];
		for (int j = 0; j < N; j++) {
			//cout << "Введiть [" << i << "][" << j << "] елемент масиву -> ";
			//cin >> mas10[i][j];
			mas10[i][j] = rand() % 50;
		}
	}
	cout << "Початковий масив:\n";
	print(mas10, M, N);
	for (int c = 0; c <= (M * N); c++) {
		int x{}, y{};
		for (int i = 0; i < M; i++)
			for (int j = (i ? 0 : 1); j < N; j++) {
				if (mas10[x][y] < mas10[i][j])
					swap(&mas10[x][y], &mas10[i][j]);
				x = i; y = j;
			}
	}
	cout << "\nЗмiнений масив:\n";
	print(mas10, M, N);
	delete [] mas10;
}