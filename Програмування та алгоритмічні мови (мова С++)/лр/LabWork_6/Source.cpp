#include "Header.h"

bool read_from_file(vector<tourist>& t) {
	debug();
	ifstream fin("tourists.txt");
	
	if (fin) {
		tourist temp;
		while (!fin.eof())
			if ((fin >> temp.name >> temp.age >> temp.gender).good())
				t.push_back(temp);
		if (t.empty()) {
			cout << "Incorrect data." << endl;
			fin.close();
			return 0;
		}
	}
	else {
		cout << "File not found." << endl;
		fin.close();
		return 0;
	}

	fin.close();
	return 1;
}

void debug() {
	string sname[]{ "Мельничук","Корпонай","Мазаракі","Ватченко","Коляда","Ганькевич","Чечет","Лисяк","Сергійчук","Грицина" };

	ofstream fout("tourists.txt");
	for (int i = 0; i < size(sname); i++)
		fout << sname[i] << " " << rand() % 50 + 18 << " " << ((rand() % 2 == 0) ? 'w' : 'm') << endl;

	fout.close();
}

int middle_age(const vector<tourist>& t) {
	int sum{};
	for (auto& a : t)
		sum += a.age;
	return sum / t.size();
}

void woman_name(const vector<tourist>& t, vector<string>& w_name) {
	for (auto& a : t)
		if (a.gender == 'w')
			w_name.push_back(a.name);
}

void write_to_file(const int& m_age, const vector<string>& w_name) {
	fstream fout("result.bin", ios::out | ios::binary);

	fout.write((char*)&m_age, sizeof(m_age));
	for (auto& a : w_name)
		fout.write((char*)&a, sizeof(a));

	fout.close();
}