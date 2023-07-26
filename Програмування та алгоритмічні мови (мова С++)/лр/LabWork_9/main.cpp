#include "Square.h"

#define DEBUG

int main() {
	srand(time(nullptr));

	vector<Square> v;

	int x1{}, y1{}, x2{}, y2{};
	for (int i = 0; i < 100; i++) {
		try {
#ifdef DEBUG
			x1 = rand() % 20 - 10, y1 = rand() % 20 - 10, x2 = rand() % 20 - 10, y2 = rand() % 20 - 10;
			Square sq(x1, y1, x2, y2);
			cout << sq << endl;
#else
			Square sq;
			cin >> sq;
#endif // DEBUG
			v.push_back(sq);
		}
		catch (const NonSquare& ex) {
#ifdef DEBUG
			cout << "\tp1: (" << Point(x1, y1) << ")" << endl;
			cout << "\tp2: (" << Point(x2, y2) << ")" << endl;
#endif // DEBUG			
			cout << "Error: " << ex.what() << endl;
		}
		cout << endl;
	}

	cout << "\nNumber of squares: " << v.size() << endl;

	int choise{};
	cout << "\nDo you want to clear the console and print only squares?\n(0 - no, 1 - yes) -> "; cin >> choise;
	if (choise == 1) {
		system("cls");
		for (int i = 0; i < v.size(); i++)
			cout << "sq" << i + 1 << " ->" << v[i] << endl;
	}

	int sq1 = rand() % v.size(), sq2 = rand() % v.size();
	cout << "\n sq" << sq1 + 1 << " == sq" << sq2 + 1 << "\t-> " << boolalpha << (v[sq1] == v[sq2]) << endl;

	sq1 = rand() % v.size(), sq2 = rand() % v.size();
	cout << "\n sq" << sq1 + 1 << " != sq" << sq2 + 1 << "\t-> " << boolalpha << (v[sq1] != v[sq2]) << endl;

	sq1 = rand() % v.size(), sq2 = rand() % v.size();
	cout << "\n sq" << sq1 + 1 << " < sq" << sq2 + 1 << "\t-> " << boolalpha << (v[sq1] < v[sq2]) << endl;

	sq1 = rand() % v.size(), sq2 = rand() % v.size();
	cout << "\n sq" << sq1 + 1 << " <= sq" << sq2 + 1 << "\t-> " << boolalpha << (v[sq1] <= v[sq2]) << endl;

	sq1 = rand() % v.size(), sq2 = rand() % v.size();
	cout << "\n sq" << sq1 + 1 << " > sq" << sq2 + 1 << "\t-> " << boolalpha << (v[sq1] > v[sq2]) << endl;

	sq1 = rand() % v.size(), sq2 = rand() % v.size();
	cout << "\n sq" << sq1 + 1 << " >= sq" << sq2 + 1 << "\t-> " << boolalpha << (v[sq1] >= v[sq2]) << endl;

	sq1 = rand() % v.size();
	cout << "\nThe closest point of sq" << sq1 << " to the origin of the coordinates(" << v[sq1].closest() << ")" << endl;

	sq2 = rand() % v.size();
	cout << "\nDiagonal of sq" << sq2 + 1 << " = " << v[sq2].diagonal() << endl;
}