#include <iostream>
#include <fstream>

using namespace std;

int main() {

	int ind = 18, d = 5, a{}, b{};
	long int c{};

	cout << endl;//Текстові файли

	{
		cout << "\t\tTEXT" << endl;
		ofstream fout("a.txt");
		cout << " a -> ";
		for (int i = 0; i < ind; i++) {
			a = rand() % 9 + 1;
			fout << a << " ";
			cout << a << " ";
		}
		cout << endl;
		fout.close();

		fout.open("b.txt");
		cout << " b -> ";
		for (int i = 0; i < ind; i++) {
			b = rand() % 9 + 1;
			fout << b << " ";
			cout << b << " ";
		}
		cout << endl;
		fout.close();

		ifstream fina("a.txt");
		ifstream finb("b.txt");
		fout.open("c.txt");
		for (int i = 0; i < ind; i++) {
			fina >> a; finb >> b;
			c = pow(a + b + d, 8) / pow(a + b, 3) + 2;
			fout << c << " ";
		}
		fout.close();

		ifstream finc("c.txt");
		cout << " c -> ";
		for (int i = 0; i < ind; i++) {
			finc >> c;
			if (i % 10 == 0 && i != 0)
				cout << endl << "      ";
			cout << c << " ";
		}
		cout << endl;
		finc.close();
	}

	cout << "\n\n\n\n";///////////////////////////////////////////

	//Бінарні файли

	{
		cout << "\t\tBINARY" << endl;
		fstream fout("a_bin", ios::binary | ios::out);
		cout << " a -> ";
		for (int i = 0; i < ind; i++) {
			a = rand() % 9 + 1;
			fout.write((char*)&a, sizeof(a));
			cout << a << " ";
		}
		cout << endl;
		fout.close();

		fout.open("b_bin", ios::binary | ios::out);
		cout << " b -> ";
		for (int i = 0; i < ind; i++) {
			b = rand() % 9 + 1;
			fout.write((char*)&b, sizeof(b));
			cout << b << " ";
		}
		cout << endl;
		fout.close();

		fstream fina("a_bin", ios::binary | ios::in);
		fstream finb("b_bin", ios::binary | ios::in);
		fout.open("c_bin", ios::binary | ios::out);
		for (int i = 0; i < ind; i++) {
			fina.read((char*)&a, sizeof(a));
			finb.read((char*)&b, sizeof(b));
			c = pow(a + b + d, 8) / pow(a + b, 3) + 2;
			fout.write((char*)&c, sizeof(c));
		}
		fout.close();
		fina.close();
		finb.close();

		fstream finc("c_bin", ios::binary | ios::in);
		cout << " c -> ";
		for (int i = 0; i < ind; i++) {
			finc.read((char*)&c, sizeof(c));
			if (i % 10 == 0 && i != 0)
				cout << endl << "      ";
			cout << c << " ";
		}
		cout << endl;
		finc.close();
	}

	return 0;
}