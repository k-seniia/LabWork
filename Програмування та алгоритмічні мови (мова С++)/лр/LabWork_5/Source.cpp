#include "Header.h"

bool read_from_file_task1(string& buf) {

#ifdef DEBUG
	debug_file_task1();
	ifstream fin("debug_string_task1.txt");
#else
	ifstream fin("string_task1.txt");
#endif

	if (fin)
		getline(fin, buf);
	else {
		cout << "File not found." << endl;
		fin.close();
		return 0;
	}
	fin.close();
	return 1;
}

void do_task1(string& buf, int& count, char let[], int num[], int& n) {
	int ch{}; bool flag{};

	for (int i = 0; buf[i]; i++) {
		if (strchr(" .,!?:;", buf[i])) {
			if (ch % 2 != 0)
				count++;
			ch = 0;
		}
		else if (isalpha(buf[i])) {
			ch++;
			buf[i] = tolower(buf[i]);
			flag = 1;
			for (int j = 0; j < n; j++)
				if (buf[i] == let[j]) {
					num[j]++;
					flag = 0;
					break;
				}
			if (flag) {
				let[n] = buf[i];
				num[n++]++;
			}
		}
	}
	if (ch % 2 != 0)
		count++;
}

void sort(char* let, int* num, const int& n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (let[j] > let[j + 1]) {
				swap(let[j], let[j + 1]);
				swap(num[j], num[j + 1]);
			}
}

void write_to_file_task1(const int& count, const char* let, const int* num, const int& n) {
	ofstream fout("result_task1.txt");
	fout << "the number of words that have an odd length -> " << count << endl;
	fout << "frequency of letters:\t";
	for (int i = 0; i < n; i++) {
		if (i % 5 == 0 && i != 0)
			fout << endl << "\t\t\t";
		fout << let[i] << " - " << num[i] << "  ";
	}
	fout.close();
}

void debug_file_task1() {
	ofstream fout("debug_string_task1.txt");
	int l = rand() % 8 + 2, lc{};
	for (int i = 0; i < rand() % 50 + 50; i++) {
		if (lc == l) {
			fout << ' ';
			lc = 0;
			l = rand() % 8 + 2;
		}
		else {
			fout << char(rand() % 26 + 97);
			lc++;
		}
	}
	fout << '\0';
	fout.close();
}

bool read_from_file_task2(string& buf) {

#ifdef DEBUG
	debug_file_task2();
	ifstream fin("debug_string_task2.txt");
#else
	ifstream fin("string_task2.txt");
#endif

	if (fin)
		getline(fin, buf);
	else {
		cout << "File not found." << endl;
		fin.close();
		return 0;
	}
	fin.close();
	return 1;
}

string do_task2(const string& buf) {
	bool flag{};
	string m, s;
	int mm{}, ss{};

	for (int i = 0; buf[i]; i++) {
		if (strchr(":", buf[i]))
			flag = 1;
		else if (isdigit(buf[i]))
			if (!flag)
				m += buf[i];
			else
				s += buf[i];
	}
	size_t pos = buf.find(m);
	mm = stoi(buf.substr(pos));
	pos = buf.find(s);
	ss = stoi(buf.substr(pos));

	return do_string(mm, ss);
}

string do_string(const int& mm, const int& ss) {
	string time;
	string ones[] = {
		"", "oдна ", "дв≥ ", "три ", "чотири ", "п\'€ть ", "ш≥сть ", "с≥м ", "в≥с≥м ", "дев\'€ть ",
		"дес€ть ", "одинадц€ть ", "дванадц€ть ", "тринадц€ть ", "чотирнадц€ть ",
		"п\'€тнадц€ть ", "ш≥стнадц€ть ", "с≥мнадц€ть ", "в≥с≥мнадц€ть ", "дев\'€тнадц€ть " };
	string tens[] = { "", "", "двадц€ть ", "тридц€ть ", "сорок ", "п\'€тдес€т " };

	if (mm == 0)
		time = "нуль ";
	else if (mm < 20)
		time = ones[mm];
	else
		time = tens[mm / 10] + ones[mm % 10];

	if (mm % 10 == 1 && mm != 11)
		time += "хвилина ";
	else if ((mm % 10 > 1 && mm % 10 < 5) && (mm < 10 || mm > 20))
		time += "хвилини ";
	else
		time += "хвилин ";

	if (ss == 0)
		time += "нуль ";
	else if (ss < 20)
		time += ones[ss];
	else
		time += tens[ss / 10] + ones[ss % 10];

	if (ss % 10 == 1 && ss != 11)
		time += "секунда";
	else if ((ss % 10 > 1 && ss % 10 < 5) && (ss < 10 || ss > 20))
		time += "секунди";
	else
		time += "секунд";

	return time;
}

void write_to_file_task2(const string& time) {
	ofstream fout("result_task2.txt");
	fout << time;
	fout.close();
}

void debug_file_task2() {
	ofstream fout("debug_string_task2.txt");

	char buffer[80];
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	strftime(buffer, 80, "%M:%S", timeinfo);
	fout << buffer << endl;
	fout << '\0';

	fout.close();
}