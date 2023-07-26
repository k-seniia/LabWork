#include <iostream>
#include <cmath>
#include <iomanip>
//������� ���������i���� �����i�. ������������ �����i�
using namespace std;

int M, N;

void task1(); void task2(); void task3(); void task4(); void task5();
void task6(); void task7(); void task8(); void task9(); void task10();

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	for (;;) {
		int choise{};
		cout << "����i�� �������� - �i� 1 �� 10" << endl;
		cout << "0 - ���i� i� ��������" << endl << endl;
		cout << "��� ���i� -> "; cin >> choise; cout << endl;
		
		if (choise >= 1 && choise <= 6) {
			cout << "���i�� ����i� �������:" << endl;
			N = rand() % 7 + 3;
			cout << "��������� ������� N -> "; /*cin >> N; M = N;*/ cout << N << endl;
		}
		else if (choise >= 7 && choise <= 10) {
			cout << "���i�� ����i� �������:" << endl;
			M = rand() % 7 + 3; 	N = rand() % 7 + 3;
			cout << "���i���� ������� M -> "; /*cin >> M;*/ cout << M << endl;
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
		default: cout << "���i���� ���i�, ������i�� ENTER �� ����i�� �����" << endl; break;
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
			//cout << "����i�� [" << i << "][" << j << "] ������� ������ -> ";
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
	cout << "\n\n----- �������� 1 -----"
		<< "\n������ ������������ (�i�i�������) ������� ������"
		<< "\n�� �������� ���������� ������� �i������i"
		<< "\n�� ����������(��i��������) ������� �� �������i�.\n\n";

	int** mas = newmas(N, N, 100);
	int max = INT_MIN, min = INT_MAX, maxi{}, maxj{}, mini{}, minj{};
	cout << "���������� �����:\n";
	print(mas, N, N);
	maxij(mas, max, maxi, maxj);
	minij(mas, min, mini, minj);
	cout << "\nmax = " << max << "\ti = " << maxi << "\tj = " << maxj << endl;
	cout << "\nmin = " << min << (min < 10 ? "\t\ti = " : "\ti = ") << mini << "\tj = " << minj << endl;
	cout << "\nC��������� ������� �i������i �� ��i��������:\n";
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - i - 1; j++)
			if (mas[j][j] > mas[j + 1][j + 1])
				swap(&mas[j][j], &mas[j + 1][j + 1]);
	print(mas, N, N);
	cout << "\nC��������� ������� �i������i �� ����������:\n";
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - i - 1; j++)
			if (mas[j][j] < mas[j + 1][j + 1])
				swap(&mas[j][j], &mas[j + 1][j + 1]);
	print(mas, N, N);
	delete[] mas;
}

void task2() {
	cout << "\n\n----- �������� 2 -----"
		<< "\n��������� �� � ������� ���i���� ���������\n\n";

	int** mas = newmas(N, N, 100);
	int* sum = new int[N * 2]{}; int mk{};
	cout << "���������� �����:\n";
	print(mas, N, N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			sum[i] += mas[i][j];
			sum[N + i] += mas[j][i];
		}
	cout << "\nC��� �������i� � ��i� ������ �� ��������: " << endl;
	for (int i = 0; i < N * 2; i++)
		cout << setw(5) << sum[i];
	cout << endl;
	for (int i = 0; i < N * 2 - 1; i++)
		if (sum[i] == sum[i + 1])
			mk++;
	if (mk == N * 2)
		cout << "\n������� � ���i���� ���������" << endl;
	else
		cout << "\n������� �� � ���i���� ���������" << endl;
	delete[] mas;
}

void task3() {
	cout << "\n\n----- �������� 3 -----"
		<< "\n������ ����� � ������������ i �i�i������� ���������"
		<< "\n�� ��i���� �� �i�����.\n\n";

	int** mas = newmas(N, N, 100);
	int max = INT_MIN, min = INT_MAX, maxi{}, maxj{}, mini{}, minj{};
	cout << "���������� �����:\n";
	print(mas, N, N);
	maxij(mas, max, maxi, maxj);
	minij(mas, min, mini, minj);
	cout << "\nmax = " << max << "\tmin = " << min << endl;
	cout << "\ni max = " << maxi << "\ti min = " << mini << endl;
	for (int j = 0; j < N; j++)
		swap(&mas[mini][j], &mas[maxi][j]);
	cout << "\n��i����� �����:\n";
	print(mas, N, N);
	delete[] mas;
}

void task4() {
	cout << "\n\n----- �������� 4 -----"
		<< "\n������ ��������� � �i�i������� i ������������ ���������."
		<< "\n�������� ���������� ��� ��������i� "
		<< "\n�� ��i�������� ������� �� �������i�.\n\n";

	int** mas = newmas(N, N, 100);
	int max = INT_MIN, min = INT_MAX, maxi{}, maxj{}, mini{}, minj{};
	cout << "���������� �����:\n";
	print(mas, N, N);
	maxij(mas, max, maxi, maxj);
	minij(mas, min, mini, minj);
	cout << "\nmax = " << max << "\tmin = " << min << endl;
	cout << "\nj max = " << maxj << "\tj min = " << minj << endl;
	cout << "\nC��������� ������� ������i� �� ��i��������:\n";
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
	cout << "\n\n----- �������� 5 -----"
		<< "\n������ ��������� � �i�i������� i ������������ ��������� ������"
		<< "\n�� ���i���� �� �i�����.\n\n";

	int** mas = newmas(N, N, 100); 
	int max = INT_MIN, min = INT_MAX, maxi{}, maxj{}, mini{}, minj{};
	cout << "���������� �����:\n";
	print(mas, N, N);
	maxij(mas, max, maxi, maxj);
	minij(mas, min, mini, minj);
	cout << "\nmax = " << max << "\tmin = " << min << endl;
	cout << "\nj max = " << maxj << "\tj min = " << minj << endl;
	for (int i = 0; i < N; i++)
		swap(&mas[i][minj], &mas[i][maxj]);
	cout << "\n��i����� �����:\n";
	print(mas, N, N);
	delete[] mas;
}

void task6() {
	cout << "\n\n----- �������� 6 -----"
		<< "\n���i���� �i����� �������� �i������"
		<< "\n�� �������/���i��� �i������i\n\n";

	int** mas = newmas(N, N, 100);
	cout << "���������� �����:\n";
	print(mas, N, N);
	cout << "\n��i����� ����� �i����i��� �� ������� �i������i\n";
	for (int i = 0; i < N; i++)
		for (int j = i; j < N; j++)
			if (i != j)
				swap(&mas[i][j], &mas[j][i]);
	print(mas, N, N);
	cout << "\n��i����� ����� �i����i��� �� ���i��� �i������i\n";
	for (int i = 0; i < N; i++)
		for (int j = N - i - 1; j < N; j++)
			if (i + j != N - 1)
				swap(&mas[i][j], &mas[N - j - 1][N - i - 1]);
	print(mas, N, N);
	delete[] mas;
}

void task7() {
	cout << "\n\n----- �������� 7 -----"
		<< "\n��������� ���������� ��i� �i������ ����� ������i.\n\n";

	int maxi{}, maxj{}, mini{}, minj{}, st = M;
	int** mas = newmas(M, N, 50);
	cout << "���������� �����:\n";
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
			cout << "\n������� ������i [" << mini << "][" << maxj << "] = " << max << "� �i������ ������\n";
		else
			st--;
	}
	if (st == 0)
		cout << "\n������� �� �� �i������ �����";
	delete[] mas;
}

void task8() {
	cout << "\n\n----- �������� 8 -----"
		<< "\n���i���� �i����� �������� ���������� �i������"
		<< "\n����������� ��i ������i� ������i\n\n";

	int** mas = newmas(M, N, 50);
	cout << "���������� �����:\n";
	print(mas, M, N);
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N / 2; j++)
			swap(&mas[i][j], &mas[i][N - 1 - j]);
	cout << "\n��i����� �����:\n";
	print(mas, M, N);
	delete[] mas;
}

void task9() {
	cout << "\n\n----- �������� 9 -----"
		<< "\n������������ ����� ������i ���, ��� �� ����i ��������"
		<< "\n���������� ��������� ����i����i���.\n\n";

	int** mas = newmas(M, N, 50);
	cout << "���������� �����:\n";
	print(mas, M, N);
	for (int c = 0; c < M; c++)
		for (int i = 0; i < M - 1; i++)
			if (mas[i][0] > mas[i + 1][0])
				for (int j = 0; j < N; j++)
					swap(&mas[i][j], &mas[i + 1][j]);
	cout << "\n��i����� �����:\n";
	print(mas, M, N);
	delete[] mas;
}

void task10() {
	cout << "\n\n----- �������� 10 -----"
		<< "\n�i���������� ������� �� ���������� �� �������i�.\n\n";

	int** mas = newmas(M, N, 50);
	cout << "���������� �����:\n";
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
	cout << "\n��i����� �����:\n";
	print(mas, M, N);
	delete[] mas;
}