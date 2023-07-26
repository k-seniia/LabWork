#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	int i = 7;
	int q = i;
	while (i > 0) {
		for (int p = 0; p < q - i + 1; p++) {
			cout << " ";
		}
		for (int j = i; j > 0; j--) {
			cout << setw(2) << '*';
		}
		cout << endl;
		i--;
	}
	i+=2;
	while (i <= q) {
		for (int p = q - i + 1; p > 0; p--) {
			cout << " ";
		}
		for (int j = 0; j < i; j++) {
			cout << setw(2) << '*';
		}
		cout << endl;
		i++;
	}

	return 0;
}