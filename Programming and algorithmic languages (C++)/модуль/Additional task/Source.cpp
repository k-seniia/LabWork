#include "Header.h"

bool read_from_file(vector<string>& log) {
	ifstream fin("log.txt");

	if (fin) {
		string buf;
		while (!fin.eof()) {
			getline(fin, buf);
			log.push_back(buf);
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

void dupli(vector<string>& log) {
	cout << " \nÄóáë³êàòè:" << endl;
	for (int i = 0; i < log.size(); i++)
		for (int j = 0; j < log.size(); j++)
			if (log[j] == log[i] && i != j) {
				cout << "\t" << log[j] << endl;
				log.erase(log.begin() + j);
			}
}

void write_to_file(const vector<string>& log) {
	ofstream fout("result.txt");

	for (int i = 0; i < log.size(); i++)
		fout << log[i] << endl;

	fout.close();
}