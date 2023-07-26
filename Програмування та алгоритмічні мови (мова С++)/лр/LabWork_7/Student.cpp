#include "Student.h"

Student::Student()
	:surname("-"), name("-"), patronymic("-"), dateOfBirth(0), address("-"), phoneNumber("+380__-___-__-__"), faculty("-"), course(0) {}

Student::Student(const string& surname, const string& name, const string& patronymic, const int& dateOfBirth, const string& address, const string& phoneNumber, const string& faculty, const int& course)
	:surname(surname), name(name), patronymic(patronymic), dateOfBirth(dateOfBirth), address(address), phoneNumber(phoneNumber), faculty(faculty), course(course) {}

Student::Student(const Student& s)
	:surname(s.surname), name(s.name), patronymic(s.patronymic), dateOfBirth(s.dateOfBirth), address(s.address), phoneNumber(s.phoneNumber), faculty(s.faculty), course(s.course) {}


string Student::get_surname() const { return surname; }
string Student::get_name() const { return name; }
string Student::get_patronymic() const { return patronymic; }
int Student::get_dateOfBirth() const { return dateOfBirth; }
string Student::get_address() const { return address; }
string Student::get_phoneNumber() const { return phoneNumber; }
string Student::get_faculty() const { return faculty; }
int Student::get_course() const { return course; }


void Student::set_all(const string& surname, const string& name, const string& patronymic, const int& dateOfBirth, const string& address, const string& phoneNumber, const string& faculty, const int& course)
{
	this->surname = surname;
	this->name = name;
	this->patronymic = patronymic;
	this->dateOfBirth = dateOfBirth;
	this->address = address;
	this->phoneNumber = phoneNumber;
	this->faculty = faculty;
	this->course = course;
}
void Student::set_surname(string surname) { this->surname = surname; }
void Student::set_name(string name) { this->name = name; }
void Student::set_patronymic(string patronymic) { this->patronymic = patronymic; }
void Student::set_dateOfBirth(int dateOfBirth) { this->dateOfBirth = dateOfBirth; }
void Student::set_address(string address) { this->address = address; }
void Student::set_phoneNumber(string phoneNumber) { this->phoneNumber = phoneNumber; }
void Student::set_faculty(string faculty) { this->faculty = faculty; }
void Student::set_course(int course) { this->course = course; }

void Student::show() const
{
	cout << "ϲ�: " << surname << " " << name << " " << patronymic << endl;
	cout << dateOfBirth << "p.,  �. " << address << ",  �. " << phoneNumber << endl;
	cout << "��������� " << faculty << ", " << course << "-� ����" << endl << endl;
}

void Student::readbin()
{
	writebin();

	ifstream fin("data.bin", ios::binary);
	if (fin) {
		string buf;
		int len{};
		fin.read((char*)&len, sizeof(len));
		buf.resize(len);
		fin.read(&buf[0], len);
		fin.close();

		size_t pos = buf.find(';');
		surname = buf.substr(0, pos);
		buf.erase(0, pos + 1);

		pos = buf.find(';');
		name = buf.substr(0, pos);
		buf.erase(0, pos + 1);

		pos = buf.find(';');
		patronymic = buf.substr(0, pos);
		buf.erase(0, pos + 1);

		pos = buf.find(';');
		dateOfBirth = stoi(buf.substr(0, pos));
		buf.erase(0, pos + 1);

		pos = buf.find(';');
		address = buf.substr(0, pos);
		buf.erase(0, pos + 1);

		pos = buf.find(';');
		phoneNumber = buf.substr(0, pos);
		buf.erase(0, pos + 1);

		pos = buf.find(';');
		faculty = buf.substr(0, pos);
		buf.erase(0, pos + 1);

		pos = buf.find(';');
		course = stoi(buf.substr(0, pos));
	}
	else {
		cout << "File not found." << endl;
		fin.close();
	}
}

void Student::writebin()
{
	string buf;

	string surnames[] = { "�����","�����","̳�����","��䳺���","̳�����","�������","�����","��������","������","�������" };
	buf = surnames[rand() % surnames->size()] + ';';

	string namesM[] = { "�����","������","�����","���������","���","������","������" };
	string namesW[] = { "���������","�����","ĳ���","������","����","�������","������" };
	string patronymics[] = { "�������","��������","����","���������","�����","�����","����","����","�����","������" };
	string name, patronymic;
	if (rand() % 2 == 0) {
		buf += namesW[rand() % namesW->size()] + ';';
		buf += patronymics[rand() % patronymics->size()] + "����" + ';';
	}
	else {
		buf += namesM[rand() % namesM->size()] + ';';
		buf += patronymics[rand() % patronymics->size()] + "����" + ';';
	}

	buf += to_string(rand() % 51 + 1955) + ';';

	string cities[] = { "���������","ʳ�����","����������","������","�����������","��������","�������","��������","�����","������������" };
	buf += cities[rand() % cities->size()] + ';';

	string codes[] = { "050","063","066","067","068","093","094","095","096","097","098","099" };
	buf += "+38" + codes[rand() % codes->size()] + "-";
	for (int i = 0; i < 7; i++) {
		buf += to_string(rand() % 10);
		if (i == 2 || i == 4)
			buf += "-";
	}
	buf += ';';

	string faculties[] = { "��", "ʲ�", "���", "���", "��", "����", "���ǲ" };
	buf += faculties[rand() % (sizeof(faculties) / sizeof(faculties[0]))] + ';';

	buf += to_string(rand() % 6 + 1) + ';';

	ofstream fout("data.bin", ios::binary);
	int len = buf.size();
	fout.write((char*)&len, sizeof(int));
	fout.write(buf.data(), buf.size());
	fout.close();
}

void task1(const Student* students, const int n)
{
	bool flag = true;
	string f{ "" };
	cout << "������ ��������� � ���������� �������: ��, ʲ�, ���, ���, ��, ����, ���ǲ\n -> ";
	cin >> f; cout << endl;
	if (f == "��" || f == "ʲ�" || f == "���" || f == "���" || f == "��" || f == "����" || f == "���ǲ") {
		flag = true;
		for (int i = 0; i < n; i++)
			if (students[i].get_faculty() == f) {
				students[i].show();
				flag = false;
			}
		if (flag)
			cout << "� ������ ���� �������� �������� ����������" << endl;
	}
	else
		cout << "������ ������� ����� ���������� ��� ����� ��������� ������� � ����������" << endl;
}

void task2(const Student* students, const int n)
{
	bool flag = true;
	string faculties[] = { "��", "ʲ�", "���", "���", "��", "����", "���ǲ" };
	for (int j = 0; j < sizeof(faculties) / sizeof(faculties[0]); j++) {
		cout << "\t��������� " << faculties[j] << ":\n" << endl;
		flag = true;
		for (int i = 0; i < n; i++)
			if (students[i].get_faculty() == faculties[j]) {
				students[i].show();
				flag = false;
			}
		if (flag)
			cout << "� ������ ���� �������� ������ ����������\n" << endl;
	}
	for (int j = 1; j <= 6; j++) {
		cout << "\t" << j << "� ����:\n" << endl;
		flag = true;
		for (int i = 0; i < n; i++)
			if (students[i].get_course() == j) {
				students[i].show();
				flag = false;
			}
		if (flag)
			cout << "� ������ ���� �������� ������ ����������\n" << endl;
	}
}

void task3(const Student* students, const int n)
{
	bool flag = true;
	int y{};
	cout << "������ �� (1955-2005)\n -> ";
	cin >> y; cout << endl;
	if (y >= 1955 && y <= 2005) {
		flag = true;
		for (int i = 0; i < n; i++)
			if (students[i].get_dateOfBirth() > y) {
				students[i].show();
				flag = false;
			}
		if (flag)
			cout << "� ������ ���� �������� ���������� ���� ����� ����" << endl;
	}
	else
		cout << "�������� �� �� ����������� � ���������� �������" << endl;
}