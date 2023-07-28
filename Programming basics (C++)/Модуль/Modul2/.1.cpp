#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	srand(time(NULL));

	int n = rand() % 8 + 2, m = rand() % 8 + 2;
	int** a = new int* [n];
	int** b = new int* [n];
	int** c = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[m];
		b[i] = new int[m];
		c[i] = new int[m];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = rand() % 20 - 10;
			b[i][j] = rand() % 20 - 10;
			if (a[i][j] < 0 && b[i][j] < 0 || a[i][j] >= 0 && b[i][j] >= 0) {
				c[i][j] = 100;
			}
			else {
				c[i][j] = 0;
			}
		}
	}

	cout << "\ta[" << n << "][" << m << "]" << endl << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}

	cout << endl << endl;
	cout << "\tb[" << n << "][" << m << "]" << endl << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(4) << b[i][j];
		}
		cout << endl;
	}

	cout << endl << endl;
	cout << "\tc[" << n << "][" << m << "]" << endl << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(4) << c[i][j];
		}
		cout << endl;
	}

	cout << endl << endl;

	return 0;
}