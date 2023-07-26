#include <iostream>
#include <cmath>
#include <iomanip>
//������� ���������i���� �����i�.
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
		cout << "����i�� �������� - �i� 1 �� 10" << endl;
		cout << "0 - ���i� i� ��������" << endl;
		cout << "��� ���i� -> "; cin >> choise; cout << endl;

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
	cout << "\n\n----- �������� 1 -----"
		<< "\n������ ������������ (�i�i�������) ������� ������"
		<< "\n�� �������� ���������� ������� �i������i"
		<< "\n�� ����������(��i��������) ������� �� �������i�.\n\n";

	int mas1[n][n]{}, max1 = INT_MIN, min1 = INT_MAX;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			//cout << "����i�� [" << i << "][" << j << "] ������� ������ -> ";
			//cin >> mas1[i][j];
			mas1[i][j] = rand() % 100;
		}
	cout << "���������� �����:\n";
	printn(mas1);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (mas1[i][j] > max1)
				max1 = mas1[i][j];
			if (mas1[i][j] < min1)
				min1 = mas1[i][j];
		}
	cout << "\nmax = " << max1 << "\tmin = " << min1 << endl;
	cout << "\nC��������� ������� �i������i �� ��i��������:\n";
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (mas1[j][j] > mas1[j + 1][j + 1])
				swap(&mas1[j][j], &mas1[j + 1][j + 1]);
	printn(mas1);
	cout << "\nC��������� ������� �i������i �� ����������:\n";
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (mas1[j][j] < mas1[j + 1][j + 1])
				swap(&mas1[j][j], &mas1[j + 1][j + 1]);
	printn(mas1);
}

void task2() {
	cout << "\n\n----- �������� 2 -----"
		<< "\n��������� �� � ������� ���i���� ���������\n\n";

	int mas2[m][m]{}, sum[m * 2]{}, mk{};
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++) {
			//cout << "����i�� [" << i << "][" << j << "] ������� ������ -> ";
			//cin >> mas2[i][j];
			mas2[i][j] = rand() % 10;
		}
	cout << "���������� �����:\n";
	printm(mas2);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++) {
			sum[i] += mas2[i][j];
			sum[m + i] += mas2[j][i];
		}
	cout << "\nC��� �������i� � ��i� ������ �� ��������: ";
	for (int i = 0; i < m * 2; i++)
		cout << setw(5) << sum[i];
	cout << endl;
	for (int i = 0; i < m * 2 - 1; i++)
		if (sum[i] == sum[i + 1])
			mk++;
	if (mk == m * 2)
		cout << "\n������� � ���i���� ���������" << endl;
	else
		cout << "\n������� �� � ���i���� ���������" << endl;
}

void task3() {
	cout << "\n\n----- �������� 3 -----"
		<< "\n������ ����� � ������������ i �i�i������� ���������"
		<< "\n�� ��i���� �� �i�����.\n\n";

	int mas3[n][n]{}, max3 = INT_MIN, max3_i{}, min3 = INT_MAX, min3_i{};
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			//cout << "����i�� [" << i << "][" << j << "] ������� ������ -> ";
			//cin >> mas3[i][j];
			mas3[i][j] = rand() % 100;
		}
	cout << "���������� �����:\n";
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
	cout << "\n��i����� �����:\n";
	printn(mas3);
}

void task4() {
	cout << "\n\n----- �������� 4 -----"
		<< "\n������ ��������� � �i�i������� i ������������ ���������."
		<< "\n�������� ���������� ��� ��������i� "
		<< "\n�� ��i�������� ������� �� �������i�.\n\n";

	int mas4[m][m]{}, max4 = INT_MIN, max4_j{}, min4 = INT_MAX, min4_j{};
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++) {
			//cout << "����i�� [" << i << "][" << j << "] ������� ������ -> ";
			//cin >> mas4[i][j];
			mas4[i][j] = rand() % 100;
		}
	cout << "���������� �����:\n";
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
	cout << "\nC��������� ������� ������i� �� ��i��������:\n";
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
	cout << "\n\n----- �������� 5 -----"
		<< "\n������ ��������� � �i�i������� i ������������ ��������� ������"
		<< "\n�� ���i���� �� �i�����.\n\n";

	int mas5[n][n]{}, max5 = INT_MIN, max5_j{}, min5 = INT_MAX, min5_j{};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//cout << "����i�� [" << i << "][" << j << "] ������� ������ -> ";
			//cin >> mas5[i][j];
			mas5[i][j] = rand() % 100;
		}
	}
	cout << "���������� �����:\n";
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
	cout << "\n��i����� �����:\n";
	printn(mas5);
}

void task6() {
	cout << "\n\n----- �������� 6 -----"
		<< "\n���������, �� � ������� ����������� �i����i���"
		<< "\n�� �������/���i��� �i������i\n\n";

	int mas6[n][n]{}, sm{};
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			//cout << "����i�� [" << i << "][" << j << "] ������� ������ -> ";
			//cin >> mas6[i][j];
			mas6[i][j] = rand() % 10;
		}
	cout << "���������� �����:\n";
	printn(mas6);
	cout << "\n�����i��� ������i �� ���������i��� �i����i��� �� ������� �i������i\n";
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
		cout << "\nM������ ���������� �i����i��� �� ������� �i������i\n";
	else
		cout << "\nM������ �� ���������� �i����i��� �� ������� �i������i\n";
	sm = 0;
	cout << "\n�����i��� ������i �� ���������i��� �i����i��� �� ���i��� �i������i\n";
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
		cout << "\nM������ ���������� �i����i��� �� ���i��� �i������i\n";
	else
		cout << "\nM������ �� ���������� �i����i��� �� ���i��� �i������i\n";
}

void task7() {
	cout << "\n\n----- �������� 7 -----"
		<< "\n��������� ���������� ��i� �i������ ����� ������i.\n\n";

	int mas7[n][n]{}, max7_j{}, min7_i{}, st = n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//cout << "����i�� [" << i << "][" << j << "] ������� ������ -> ";
			//cin >> mas7[i][j];
			mas7[i][j] = rand() % 50;
		}
	}
	cout << "���������� �����:\n";
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
			cout << "\n������� ������i [" << min7_i << "][" << max7_j << "] = " << max7 << "� �i������ ������\n";
		else
			st--;
	}
	if (st == 0)
		cout << "\n������� �� �� �i������ �����";
}

void task8() {
	cout << "\n\n----- �������� 8 -----"
		<< "\n���i���� �i����� �������� ���������� �i������"
		<< "\n����������� ��i ������i� ������i\n\n";

	//cin >> M >> N;
	M = rand() % 8 + 2; 	N = rand() % 8 + 2;
	int** mas8 = new int* [M];
	for (int i = 0; i < M; i++) {
		mas8[i] = new int[N];
		for (int j = 0; j < N; j++) {
			//cout << "����i�� [" << i << "][" << j << "] ������� ������ -> ";
			//cin >> mas8[i][j];
			mas8[i][j] = rand() % 50;
		}
	}
	cout << "���������� �����:\n";
	print(mas8, M, N);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N / 2; j++) {
			swap(&mas8[i][j], &mas8[i][N - 1 - j]);
		}
	}
	cout << "\n��i����� �����:\n";
	print(mas8, M, N);
	delete [] mas8;
}

void task9() {
	cout << "\n\n----- �������� 9 -----"
		<< "\n������������ �� ����� ���, ��� �� ����i ��������"
		<< "\n���������� ��������� ����i����i���.\n\n";

	//cin >> M >> N;
	M = rand() % 8 + 2; 	N = rand() % 8 + 2;
	int** mas9 = new int* [M];
	for (int i = 0; i < M; i++) {
		mas9[i] = new int[N];
		for (int j = 0; j < N; j++) {
			//cout << "����i�� [" << i << "][" << j << "] ������� ������ -> ";
			//cin >> mas9[i][j];
			mas9[i][j] = rand() % 50;
		}
	}
	cout << "���������� �����:\n";
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
	cout << "\n��i����� �����:\n";
	print(mas9, M, N);
	delete [] mas9;
}

void task10() {
	cout << "\n\n----- �������� 10 -----"
		<< "\n�i���������� ������� �� ���������� �� �������i�.\n\n";

	//cin >> M >> N;
	M = rand() % 8 + 2; 	N = rand() % 8 + 2;
	int** mas10 = new int* [M];
	for (int i = 0; i < M; i++) {
		mas10[i] = new int[N];
		for (int j = 0; j < N; j++) {
			//cout << "����i�� [" << i << "][" << j << "] ������� ������ -> ";
			//cin >> mas10[i][j];
			mas10[i][j] = rand() % 50;
		}
	}
	cout << "���������� �����:\n";
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
	cout << "\n��i����� �����:\n";
	print(mas10, M, N);
	delete [] mas10;
}